/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 00:30:51 by seukim            #+#    #+#             */
/*   Updated: 2020/03/27 00:30:51 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstiter(t_list &lst, void (*f)(void *))
{

	t_list *next;

	if (lst != NULL)
	{
		next = lst;
		while (1)
		{
			(*f)(next->content);
			next = next->next;
			if (next == NULL)
				return ;
		}
	}
}
