/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bsq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 15:00:35 by erli              #+#    #+#             */
/*   Updated: 2018/07/23 21:40:34 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_bsq.h"
#include <stdlib.h>
#include "ft_proto.h"

int		get_nl(t_list *list, t_global *glob)
{
	int nb;
	int pow;
	int i;

	nb = list->c - '0';
	i = 0;
	pow = 10;
	next_link(&list);
	while (pow <= 1000000000 && list != 0 && list->c >= '0' && list->c <= '9')
	{
		nb = nb + (list->c - '0') * pow;
		next_link(&list);
		pow = pow * 10;
	}
	if (pow <= 1000000000 && list != 0)
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
	int i;
	int nl;

	i = 0;
	if (list == 0 || list->next == 0 || list->next->next == 0)
		return (-1);
	glob->full = list->c;
	next_link(&list);
	glob->obs = list->c;
	next_link(&list);
	if (glob->obs == list->c)
		return (-1);
	glob->empty = list->c;
	if (list->next == 0)
		return (-1);
	nl = get_nl(list->next, glob);
	if (nl < 0)
		return (-1);
	if (!((glob->map) = (int **)malloc(sizeof(int*) * nl)))
		return (-2);
	return (1);
}

int		test_char(char c, t_global *glob)
{
	if (c != glob->empty && c != glob->obs)
		return (0);
	return (1);
}
