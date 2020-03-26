/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 23:43:27 by seukim            #+#    #+#             */
/*   Updated: 2020/03/26 23:43:27 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*next;

	size = 0;
	next = lst;
	while (next != NULL)
	{
		next = next->next;
		size++;
	}
	return (size);
}
