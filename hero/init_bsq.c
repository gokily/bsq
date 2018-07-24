/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 11:05:08 by erli              #+#    #+#             */
/*   Updated: 2018/07/24 09:30:31 by erli             ###   ########.fr       */
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

	glob->nc = nc;
	map_alloc(glob, 0);
	i = 0;
	while (i < glob->nc && list != 0)
	{
		symbol_to_int(glob, list->c, 0, i);
		next_link(&list);
		i++;
	}
	return (0);
}

int		convert_map_bsq(int fd, t_global *glob, int check)
{
	int		i;
	int		j;
	char	buff[2];

	if (check == 0)
		return (-1);
	i = 0;
	j = 1;
	buff[0] = 'e';
	map_alloc(glob, j);
	while (read(fd, buff, 1) != 0 && check == 1)
	{
		if (buff[0] != '\n')
		{
			test_char(buff[0], glob);
			symbol_to_int(glob, buff[0], j, i);
			i++;
		}
		if (buff[0] == '\n' && i != glob->nc)
			return (-1);
		if (buff[0] == '\n' && i == glob->nc)
		{
			j++;
			i = 0;
			map_alloc(glob, j);
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
	i = 0;
	list = 0;
	while (read(fd, buff, 1) != 0 && buff[0] != '\n' && check == 1)
	{
		check = test_char(buff[0], glob);
		list = add_link_back(list, buff[0]);
		i++;
	}
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
