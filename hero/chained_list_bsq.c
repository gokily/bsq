/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_chained_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 11:16:40 by erli              #+#    #+#             */
/*   Updated: 2018/07/23 19:58:17 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_bsq.h"
#include <stdlib.h>
#include <stdio.h>

t_list	*create_elem(char c)
{
	t_list *list;

	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (0);
	list->c = c;
	list->next = 0;
	return (list);
}

t_list	*add_link_front(t_list *list, char data)
{
	t_list *tmp;

	tmp = create_elem(data);	
	if (list == 0)
		return (tmp);
	tmp->next = list;
	list = tmp;
	return (list);
}

t_list	*add_link_back(t_list *list, char data)
{
	t_list *tmp;

	if (list == 0)
		return (create_elem(data));
	tmp = list;
	while (tmp->next != 0)
		tmp = tmp->next;
	tmp->next = create_elem(data);
	return (list);
}

void	next_link(t_list **list)
{
	t_list *tmp;

	if (*list == 0 || list == 0)
		return ;
	tmp = *list;
	*list = (*list)->next;
	free(tmp);
}

void	print_list(t_list *list)
{
	while (list != 0)
	{
		printf("%c\t", list->c);
		list = list->next;
	}
	printf("\n");
}
