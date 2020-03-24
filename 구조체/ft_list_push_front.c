/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 23:41:13 by seukim            #+#    #+#             */
/*   Updated: 2020/03/24 23:41:13 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *date)
{
	t_list *new_list;

	new_list = ft_create_elem(date);
	new_list ->next = (*begin_list);
	*begin_list = new_list;
}
