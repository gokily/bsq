/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 11:05:08 by erli              #+#    #+#             */
/*   Updated: 2018/07/23 17:01:49 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_bsq.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

void	convert_first_line(t_list *list, t_global *glob, int i)
{
	int		i;
	t_list	*tmp;

	i = 0;
	while (i < glob->nl)
	{
		if (!(glob->map[i] = (int *)malloc(sizeof(int) * glob->nc)))
			return (0);
		i++;
	}
	i = 0;
	while (i < glob->nc)
	{
		symbol_to_int(glob, 0, i, list->c);
		tmp = list;
		list = list->next;
		free(tmp);
		i++;
	}
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
	buff = "e";
	while (read(0, buff, 1) != 0 && check == 1)
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
}

int		int_bsq(int fd, t_global *glob)
{
	char	buff[2];
	int		i;
	t_list	*list;
	int		check;

	i = 0;
	buff = "e"
	while (ret = read(fd, buff, 1) != 0 && buff[0] != '\n')
	{
		if (buff[0] >= '0' && buff[0] <= '9')
			list = add_link_back(list, buff[0]);
		else if(buff[0] >= ' ' && buff[0] < 127)
			list = add_link_front(list, buff[0]);
		else
			return (-1);
		i++;
	}
	if (i > 13)
		return (-1);
	check = test_map_param(list, glob);
	while (read(fd, buff, 1) != 0 && buff[0] != '\n' && check == 1)
	{
		check = test_char(buff[0], glob);
		list == add_link_back(list, buff[0]);
		i++;
	}
	convert_first_line(list, glob, i);
	return (convert_map_bsq(fd, glob, check);
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
