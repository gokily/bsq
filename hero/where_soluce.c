/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   where_soluce.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutricot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 23:40:46 by hutricot          #+#    #+#             */
/*   Updated: 2018/07/25 12:03:50 by hutricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_bsq.h"
#include <stdlib.h>

int			that_work(t_sq co, int **tab, int s)
{
	if (co.top->y == 0 && co.top->x == 0)
		return (tab[co.top->y + s][co.top->x + s]);
	if (co.top->y == 0)
	{
		return (tab[co.top->y + s][co.top->x + s] -
			tab[co.top->y + s][co.top->x - 1]);
	}
	if (co.top->x == 0)
	{
		return (tab[co.top->y + s][co.top->x + s] -
			tab[co.top->y - 1][co.top->x + s]);
	}
	return (tab[co.top->y + s][co.top->x + s] +
			tab[co.top->y - 1][co.top->x - 1]
				- tab[co.top->y - 1][co.top->x + s] -
					tab[co.top->y + s][co.top->x - 1]);
}

t_sq		r_v(int y, int x, int y1, int x1)
{
	t_sq	v;

	v.top = malloc(sizeof(t_coord));
	v.bot = malloc(sizeof(t_coord));
	v.top->y = y;
	v.top->x = x;
	v.bot->y = y1;
	v.bot->y = x1;
	return (v);
}

t_sq		where(int **tab, t_global data)
{
	t_sq	co;
	t_sq	best;
	int		s;

	co = r_v(0, 0, 0, 0);
	s = 0;
	while (co.top->y + s < data.nl)
	{
		while (co.top->x + s < data.nc)
		{
			if (that_work(co, tab, s) == 0)
			{
				best = r_v(co.top->y, co.top->x,
						(co.top->y) + s, (co.top->x) + s);
				s++;
			}
			else if (co.top->x + s < data.nc)
				co.top->x++;
		}
		co.top->x = 0;
		co.top->y++;
	}
	best.bot->y = best.top->y + s - 1;
	best.bot->x = best.top->x + s - 1;
	return (best);
}
