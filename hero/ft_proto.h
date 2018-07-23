/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proto.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 11:40:40 by erli              #+#    #+#             */
/*   Updated: 2018/07/23 11:45:29 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROTO_H
# define FT_PROTO_H

# include "map_bsq.h"

t_list		*create_elem(char c);
t_list		*add_link_front(t_list *list, char c);
t_list		*add_link_back(t_list *list, char c);
t_global	*init_global(t_global *glob);

#endif
