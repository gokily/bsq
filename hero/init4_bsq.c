/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 11:05:08 by erli              #+#    #+#             */
/*   Updated: 2018/07/25 17:25:35 by erli             ###   ########.fr       */
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
	int		incr;

	glob->nc = nc;
	map_alloc(glob, 0);
	i = 0;
	incr = 0;
	while (i < glob->nc && list != 0)
	{
		if (list->c == glob->obs)
			incr++;
		glob->map[0][i] = incr;
		next_link(&list);
		i++;
	}	
	return (0);
}

int		convert_map_bsq(int fd, t_global *glob, int check)
{
	int		i;
	int		j;
	int 	k;
	char	buff[BUFF_SIZE + 1];

	if (check == -1)
		return (-1);
	i = 0;
	j = 1;
	buff[BUFF_SIZE] = '\0';
	map_alloc(glob, j);
	while (read(fd, buff, BUFF_SIZE) != 0 && check == 1)
	{
		k = 0;
		while (buff[k] != '\0' && check == 1)
		{
			if (buff[k] != '\n')
			{
				check = test_char(buff[k], glob);
				symbol_to_int(glob, buff[k], j, i);
				i++;
			}
			if (buff[k] == '\n' && i != glob->nc)
				return (-1);
			if (buff[k] == '\n' && i == glob->nc)
			{
				j++;
				i = 0;
				map_alloc(glob, j);
			}
			k++;
		}
	}
	printf("obstacle found : %d\n", glob->map[glob->nl-1][glob->nc-1]);
	if (j != glob->nl)
		check = -1;
	return (check);
}

int		init_bsq(int fd, t_global *glob)
{
	char	buff[2];
	int		i;
	t_list	*list;
	int		check;

	i = 0;
	list = 0;
	buff[0] = 'e';
	while (read(fd, buff, 1) != 0 && buff[0] != '\n' && i <= 13)
	{
		if(buff[0] >= ' ' && buff[0] < 127)
			list = add_link_front(list, buff[0]);
		else
			return (-1);
		i++;
	}
	if (i == 0 || i > 13)
		return (-1);
	check = test_map_param(list, glob);
	i = 0;
	list = 0;
	while (read(fd, buff, 1) != 0 && buff[0] != '\n' && check == 1)
	{
		check = test_char(buff[0], glob);
		list = add_link_back(list, buff[0]);
		i++;
	}
	if (i == 0)
		check = -1;
	if (check == -1)
		return (-1);
	convert_first_line(list, glob, i);
	return (convert_map_bsq(fd, glob, check));
}

int		main(int argc, char **argv)
{
	int			fd;
	int			i;
	t_global	*glob;
	t_sq 		*sol;
	int			error;

	glob = init_global();
	i = 1;

	if (argc == 1)
	{
		error = init_bsq(0, glob);
		if (error == -1)
			puts("Map Error");
		else
		{
			sol = find_solution(glob->map, *glob);
			print_solution(*sol, *glob);
		}
	}	
	else
	{
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			error = init_bsq(fd, glob);
			close(fd);
			if (error == -1)
				puts("Map Error");
			else
			{		
//				sol = find_solution(glob->map, *glob);
//				print_solution(*sol, *glob);
			}
			if (argc > 2 && i < argc - 1)
				printf("\n");
			i++;
		}
	}
	return (0);
}
