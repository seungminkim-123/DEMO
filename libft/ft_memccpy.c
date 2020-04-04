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
	int i;

	i = 0;
	p1 = (unsigned char*)dest;
	p2 = (unsigned char*)src;
	while (i < n)
	{
		if (*p2 != (unsigned char)c)
		{
			*p1++ = *p2++;
			i++;
		}
		else
			return (dest + i + i);
	}
	return ('\0');
}
