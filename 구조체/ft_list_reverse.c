/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 15:41:33 by seukim            #+#    #+#             */
/*   Updated: 2020/03/25 15:41:33 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list *next;
	t_list *previous;
	t_list *current;

	if (*begin_list == 0)
		return ;
	current = *begin_list;
	while (current != NULL)
	{
		next = current ->next;
		current ->next = previous;
		previous = current;
		current = next;
	}
}
