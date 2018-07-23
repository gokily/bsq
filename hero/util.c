/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 14:24:34 by erli              #+#    #+#             */
/*   Updated: 2018/07/23 14:33:16 by erli             ###   ########.fr       */
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

