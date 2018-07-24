/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 13:12:08 by gly               #+#    #+#             */
/*   Updated: 2018/07/23 13:58:36 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_bsq.h"
#include "proto.h"

void	print_pos(t_coord tmp, int **tab, t_sq sol, t_global map)
{
	if (tmp.x >= sol.top->x && tmp.x <= sol.bot->x &&
			tmp.y >= sol.top->y && tmp.y <= sol.bot->y)
		ft_putchar(map.full);
	else if (tab[tmp.y][tmp.x] - tab[tmp.y - 1][tmp.x - 1] -
			tab[tmp.y - 1][tmp.x] + tab[tmp.y - 1][tmp.x - 1])
		ft_putchar(map.empty);
	else
		ft_putchar(map.obs);
}

void	print_solution(t_sq sol, t_global map_info)
{
	t_coord tmp;
	int		**tab;

	tab = map_info.map;
	tmp.y = 0;
	tmp.x = 0;
	while (tmp.y < map_info.nc)
	{
		tmp.x = 0;
		while (tmp.x < map_info.nl)
		{
			print_pos(tmp, tab, sol, map_info);
			tmp.x++;
		}
		tmp.y++;
	}
}
