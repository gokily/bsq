/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 14:24:34 by erli              #+#    #+#             */
/*   Updated: 2018/07/23 16:54:45 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_bsq.c"
#include <stdlib.h>

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
	if (x == 0)
		glob->tab[y][x] = (y == 0) ? incr : glob->tab[y - 1][x] + incr;
	else
		glob->tab[y][x] = (y == 0) ? glob->tab[y][x - 1] + incr :
			glob->tab[y - 1][x] + glob->tab[y][x - 1] + incr);
}
