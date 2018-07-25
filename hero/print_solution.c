/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 13:12:08 by gly               #+#    #+#             */
/*   Updated: 2018/07/25 17:00:03 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_bsq.h"
#include "ft_proto.h"
#include <unistd.h>
#include <stdlib.h>

int		is_obs(int x, int y, int **tab)
{
	if (x >= 1)
	{
		if (y >= 1)
			return (tab[y - 1][x - 1] - tab[y][x - 1] -
					tab[y - 1][x] + tab[y][x]);
		else
			return (tab[y][x] - tab[y][x - 1]);
	}
	else if (y >= 1)
		return (tab[y][x] - tab[y - 1][x]);
	else
		return (tab[y][x]);
}

void	print_line(t_sq sol, t_global map, int y, char *str)
{
	int		x;

	x = 0;
	while (x < map.nc)
	{
		if (x >= sol.top->x && x <= sol.bot->x &&
				y >= sol.top->y && y <= sol.bot->y)
			str[x] = map.full;
		else if (!is_obs(x, y, map.map))
			str[x] = map.empty;
		else
			str[x] = map.obs;
		x++;
	}
	str[x] = '\n';
	write(1, str, x + 1);
}

void	print_solution(t_sq sol, t_global map_info)
{
	char	*str;
	int		nline;

	if (!(str = malloc(sizeof(char) * map_info.nc)))
		return ;
	nline = 0;
	while (nline < map_info.nl)
	{
		print_line(sol, map_info, nline, str);
		nline++;
	}
	free(str);
}
