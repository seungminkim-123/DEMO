/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 21:14:30 by seukim            #+#    #+#             */
/*   Updated: 2020/02/25 21:14:30 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *prt, size_t n)
{
	unsigned char *p1;
	int i;

	p1 = (unsigned char*)prt;
	while (n > 0)
	{
		*p1++ = '0';
		n--;
	}
}
