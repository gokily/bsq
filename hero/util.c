/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 14:24:34 by erli              #+#    #+#             */
/*   Updated: 2018/07/24 09:32:14 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_bsq.h"
#include <stdlib.h>
#include <stdio.h>

t_global	*init_global(void)
{
	t_global *glob;

	if (!(glob = (t_global *)malloc(sizeof(t_global))))
		return (0);
	glob->nc = 0;
	glob->nl = 0;
	return (glob);
}

void		symbol_to_int(t_global *glob, char c, int y, int x)
{
	int incr;
	int top;
	int behind;

	incr = 0;
	top = 0;
	behind = 0;
	if (c == glob->obs)
		incr = 1;
	if (x == 0)
		behind = 0;
	else
		behind = (glob->map)[y][x - 1];
	if (y == 0)
		top = 0;
	else
	{
		top = (glob->map)[y - 1][x];
	}
	(glob->map)[y][x] = top + behind + incr;
	if (x >= 1 && y >= 1)
		(glob->map)[y][x] -= (glob->map)[y - 1][x - 1];
}

int			map_alloc(t_global *glob, int i)
{
	if (!((glob->map)[i] = (int *)malloc(sizeof(int) * glob->nc)))
		return (-2);
	return (0);
}
