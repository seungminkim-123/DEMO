/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 22:29:22 by seukim            #+#    #+#             */
/*   Updated: 2020/02/25 22:29:22 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char *p1;
	unsigned char *p2;

	p1 = (unsigned char*)dest;
	p2 = (unsigned char*)src;
	if (n <= 0)
	{
		while(n > 0)
		{
			*p1++ = *p2++;
			if ((unsigned char)c == *(p2 - 1))
				return (p1);
			n--;
		}
	}
	return ('\0');
}
