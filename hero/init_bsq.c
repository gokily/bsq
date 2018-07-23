/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 11:05:08 by erli              #+#    #+#             */
/*   Updated: 2018/07/23 20:03:37 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_bsq.h"
#include "ft_proto.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

int		convert_first_line(t_list *list, t_global *glob, int nc)
{
	int		i;

	print_list(list);
	i = 0;
	glob->nc = nc;
	printf("nc = %d\n", glob->nc);

	while (i < glob->nl)
	{
		print_list(list);
		if (!(glob->map[i] = (int *)malloc(sizeof(int) * glob->nc)))
			return (-2);
		i++;
	}
	i = 0;
	puts("apres malloc");
	print_list(list);
	while (i < glob->nc && list != 0)
	{
		printf("Avant conversion en int\n");
		symbol_to_int(glob, list->c, 0, i);
		printf("list c = %c\n",list->c);
		list = list->next;
		i++;
	}


	i = 0;
	printf("premiere ligne\n");
	while (i < glob->nc)
	{
		printf("%d, ", glob->map[0][i]);
		i++;
	}
	printf("\n");
	return (0);
}

int		convert_map_bsq(int fd, t_global *glob, int check)
{
	int i;
	int j;
	char buff[2];

	if (check == 0)
		return (-1);
	i = 0;
	j = 1;
	buff[0] = 'e';
	while (read(fd, buff, 1) != 0 && check == 1)
	{
		if (buff[0] != '\n')
		{
			check = test_char(buff[0], glob);
			symbol_to_int(glob, buff[0], j, i);
			i++;
		}
		else if (i != glob->nc)
			return (-1);
		else
		{
			j++;
			i = 0;
		}
	}
	return (0);
}

int		init_bsq(int fd, t_global *glob)
{
	char	buff[2];
	int		i;
	t_list	*list;
	int		check;

	i = 0;
	buff[0] = 'e';
	while (read(fd, buff, 1) != 0 && buff[0] != '\n')
	{

		if(buff[0] >= ' ' && buff[0] < 127)
			list = add_link_front(list, buff[0]);
		else
			return (-1);
		i++;
	}
	if (i > 13)
		return (-1);
	check = test_map_param(list, glob);
	printf(" check = %d\n", check);
	printf("Parametre : nl = %d, empty = %c, obs = %c, full = %c\n", glob->nl, glob->empty, glob->obs, glob->full);
	i = 0;
	list = 0;
	while (read(fd, buff, 1) != 0 && buff[0] != '\n' && check == 1)
	{
		check = test_char(buff[0], glob);
		list = add_link_back(list, buff[0]);
		printf("char = %c\n", list->c);
		i++;
	}
	print_list(list);
	printf(" check = %d et premier char = %c\n", check, list->c);
	convert_first_line(list, glob, i);
	return (convert_map_bsq(fd, glob, check));
}

int		main(int argc, char **argv)
{
	int			fd;
	int			i;
	t_global	*glob;

	glob = init_global();
	i = 1;
	if (argc == 1)
		init_bsq(0, glob);
	else
	{
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			init_bsq(fd, glob);
			close(fd);
			i++;
		}
	}




	return (0);
}
