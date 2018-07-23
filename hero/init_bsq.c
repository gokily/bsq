/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 11:05:08 by erli              #+#    #+#             */
/*   Updated: 2018/07/23 13:01:04 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_bsq.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

int		int_bsq(int fd, t_global *glob)
{
	char	buff[2];
	int		i;
	t_list	*list;
	int		check;

	i = 0;
	buff[1] = '\0';
	buff[0] = 'e';
	while (ret = read(fd, buff, 1) != 0 && buff[0] != '\n')
	{
		if (buff[0] >= '0' && buff[0] <= '9')
			list = add_link_back(list, buff[0]);
		else if(buff[0] >= ' ' && buff[0] < 127)
			list = add_link_front(list, buff[0]);
		else
			return (-1);
	}
	check = test_map_param(list, glob);
	while (read(fd, buff, 1) != 0 && buff[0] != '\n' && check == 1)
	{
		check = test_char(buff[0], glob);
		list == add_link_back(list, buff[0]);
		i++;
	}
	convert_first_line(list, glob, i);
	return (convert_map_bsq(glob, map);
}

int		main(int argc, char **argv)
{
	int			fd;
	int			i;
	t_global	*glob;

	glob = init_global();
	i = 1;
	if (argc == 1)
		bsq_init(0, glob);
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
