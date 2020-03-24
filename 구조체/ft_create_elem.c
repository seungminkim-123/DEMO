/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 02:33:01 by seukim            #+#    #+#             */
/*   Updated: 2020/03/24 02:33:01 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list		*ft_create_elem(void *date)
{
	t_list *p1;
	p1 = (t_list*)malloc(sizeof(t_list));
	p1 -> next = 0;
	p1 -> date = date;
	return (p1);
}
