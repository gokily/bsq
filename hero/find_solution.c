/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_solution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 10:49:09 by gly               #+#    #+#             */
/*   Updated: 2018/07/25 16:12:48 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_bsq.h"
#include <stdlib.h>
#include <stdio.h>

int		valid_place(t_coord pos, int size, int **tab, t_global map_info)
{
	if ((pos.x + size) > map_info.nc || (pos.y + size) > map_info.nl)
		return (0);
	if (pos.x >= 1)
	{
		if (pos.y >= 1)
			return (!(tab[pos.y + size - 1][pos.x + size - 1] -
						tab[pos.y + size - 1][pos.x - 1] -
						tab[pos.y - 1][pos.x + size - 1] +
						tab[pos.y - 1][pos.x - 1]));
		else
			return (!(tab[pos.y + size - 1][pos.x + size - 1] -
						tab[pos.y + size - 1][pos.x - 1]));
	}
	else if (pos.y >= 1)
		return (!(tab[pos.y + size - 1][pos.x + size - 1] -
					tab[pos.y - 1][pos.x + size - 1]));
	else
		return (!(tab[pos.y + size - 1][pos.x + size - 1]));
}

t_sq	*init_sol(void)
{
	t_sq	*sol;

	if (!(sol = malloc(sizeof(*sol))))
		return (sol);
	if (!(sol->bot = malloc(sizeof(*sol->bot))))
		return (sol);
	if (!(sol->top = malloc(sizeof(*sol->top))))
		return (sol);
	sol->top->x = -1;
	sol->top->y = -1;
	sol->bot->x = -1;
	sol->bot->y = -1;
	return (sol);
}

t_sq	*fill_sol(t_coord tmp, int size, t_sq *sol)
{
	sol->top->x = tmp.x;
	sol->top->y = tmp.y;
	sol->bot->x = tmp.x + size - 1;
	sol->bot->y = tmp.y + size - 1;
	return (sol);
}

t_sq	*find_solution(int **tab, t_global map_info)
{
	int		size;
	t_coord	tmp;
	t_sq	*sol;

	tmp.y = 0;
	size = 1;
	sol = init_sol();
	while (tmp.y + size - 1 < map_info.nl)
	{
		tmp.x = 0;
		while (tmp.x + size - 1 < map_info.nc)
		{
			while (valid_place(tmp, size, tab, map_info))
			{
				sol = fill_sol(tmp, size, sol);
				size++;
			}
			tmp.x++;
		}
		tmp.y++;
	}
	if (sol->top->x == -1)
		puts("No solution Eric !");
	printf("Size of the square is %i\n", size);
	return (sol);
}
