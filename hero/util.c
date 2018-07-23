/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 14:24:34 by erli              #+#    #+#             */
/*   Updated: 2018/07/23 18:58:42 by erli             ###   ########.fr       */
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

	incr = 0;
	if (c == glob->obs)
		incr = 1;
//	printf("incr = %d\n", incr);
	if (x == 0)
		glob->map[y][x] = (y == 0) ? incr : glob->map[y - 1][x] + incr;
	else
		glob->map[y][x] = (y == 0) ? glob->map[y][x - 1] + incr :
			glob->map[y - 1][x] + glob->map[y][x - 1] + incr;
}
