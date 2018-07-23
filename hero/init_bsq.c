/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 11:05:08 by erli              #+#    #+#             */
/*   Updated: 2018/07/23 11:46:07 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_bsq.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

void	int_bsq(int fd)
{
	char buff[2];



}

int		main(int argc, char **argv)
{
	int			fd;
	int			i;
	t_global	*glob;


	i = 1;
	if (argc == 1)
		bsq_init(0);
	else
	{
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			init_bsq(fd);
			close(fd);
			i++;
		}
	}
	return (0);
}
