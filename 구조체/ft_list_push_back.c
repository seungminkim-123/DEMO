/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 00:05:52 by seukim            #+#    #+#             */
/*   Updated: 2020/03/25 00:05:52 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *date)
{
	t_list *list;

	if (*begin_list == 0)
		list = ft_create_elem(date);
	else
		ft_list_push_back(&((*begin_list) ->next), date));
}
