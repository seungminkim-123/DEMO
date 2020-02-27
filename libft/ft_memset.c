/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:42:11 by seukim            #+#    #+#             */
/*   Updated: 2020/02/25 16:42:11 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *prt, int value, size_t num)
{
	unsigned char *p1;
	unsigned char insert;
	int i;

	insert =(unsigned char)value;
	p1 = (unsigned char *)prt;
	i = 0;
	while (num > 0)
	{
		p1[i] = insert;
		num--;
		i++;
	}
	return (prt);
}
