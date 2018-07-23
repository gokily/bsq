/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bsq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 15:00:35 by erli              #+#    #+#             */
/*   Updated: 2018/07/23 17:29:37 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_bsq.h"

int		get_nl(t_list *list, t_global *glob)
{
	int nb;
	int pow;

	nb = list->c - '0';
	i = 0;
	pow = 10;
	list = list->next;
	while (pow < 1000000000 && list != 0 && list->c >= '0' && list->c <= '9')
	{
		nb = nb + (list->c - '0') * pow;
		list = list->next;
		pow = pow * 10;
	}
	if (pow < 1000000000 && list != 0)
		return (-1);
	if (list != 0 && nb > 147483647)
		return (list->c - '0' > 1 ? 0 : 1);
	if (list != 0 && nb <= 147483647)
		return (list->c - '0' > 2 ? 0 : 1);
	if (nb < 0)
		return (-1);
	glob->nl = nb;
	return (1);
}

int		test_map_param(t_list *list, t_global *glob)
{

	i = 0;
	if (list == 0 || list->next == 0 || list->next->next == 0)
		return (-1);
	glob->full = list->c;
	list = list->next;
	glob->obs = list->c;
	list = list->next;
	if (glob->obs == list->c)
		return (-1);
	glob->empty = list->c;
	if (list->next == 0)
		return (-1);
	return (get_nl(list->next, glob));
}

int		test_char(char c, t_global *glob)
{
	if (c != glob->empty && c != glob->obs)
		return (0);
	return (1);
}
