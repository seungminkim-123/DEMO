/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 05:07:46 by seukim            #+#    #+#             */
/*   Updated: 2020/02/26 05:07:46 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *prt1, const void *prt2, size_t n)
{
	unsigned char *p1;
	unsigned char *p2;

	p1 = (unsigned char*)prt1;
	p2 = (unsigned char*)prt2;
	if (n == 0)
		return (0);
	while (n > 0)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		p2++;
		p1++;
		n--;
	}
	return (0);
}
