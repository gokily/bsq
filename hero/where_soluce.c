/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   where_soluce.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutricot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 14:46:54 by hutricot          #+#    #+#             */
/*   Updated: 2018/07/23 17:33:50 by hutricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_ok(int **tab, t_sq *v)
{
	int nb;

	if	(tab[v->top.y])
		nb = 0;
	else
		nb = tab[v->bot.y][v->bot.x] + tab[v->top.y - 1][v->top.x - 1] - 
			tab[v->bot.y][v->top.x - 1] - tab[v->top.y - 1][v->bot.x];
	if (nb = 0)
		return (1);
	else
		return (0);
}

t_sq	ft_value(y1, x1, y2, x2)
{
	t_sq *v;

	value->bot.y1 = 0;
	value->bot.x1 = 0;
	value->top.y2 = 0;
	value->top.x2 = 0;

}

t_sq	*where(t_sq sol,int **tab,)
{
	t_sq *value;
	t_sq *best_sq;
	int s;
	
	value = ft_value(0, 0, 0, 0);
	s = 0;
	while (value->bot.->y < t_global.nl && value->bot->y < t_global.nc)
	{	
		if (ft_ok(tab, value))
		{
			value->bot.x++;
			value->bot.y++;
			best_sq = value
			s++;
		}
		else if (x < t_global.nc)
		{
			value->bot.x++;
			value->top.x++;
		}
		else
			value = ft_value(value->bot.y + 1 , s, value->top.y, 0);
	}
	return (best_sq);
}
