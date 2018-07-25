/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_result.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutricot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 17:23:21 by hutricot          #+#    #+#             */
/*   Updated: 2018/07/25 12:09:15 by hutricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_bsq.h"
#include <unistd.h>

int		if_ft(int **tab, int y, int x)
{
	if (y == 0 && x == 0)
		return (tab[y][x]);
	if (y < 1)
		return (tab[y][x] - tab[y][x - 1]);
	if (x < 1)
		return (tab[y][x] - tab[y - 1][x]);
	return (tab[y][x] + tab[y - 1][x - 1] - tab[y - 1][x] - tab[y][x - 1]);
}

void	ft_print_result(t_sq b_s, t_global *glob)
{
	int x;
	int y;
	int **tab;

	tab = glob->map;
	x = 0;
	y = 0;
	while (y < glob->nl)
	{
		x = 0;
		while (x < glob->nc)
		{
			if (if_ft(tab, y, x) > 0)
				write(1, &glob->obs, 1);
			else if (y <= b_s.bot->y && x <= b_s.bot->x &&
					y >= b_s.top->y && x >= b_s.top->x)
				write(1, &glob->full, 1);
			else
				write(1, &glob->empty, 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}
