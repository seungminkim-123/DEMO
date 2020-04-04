/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 23:13:23 by seukim            #+#    #+#             */
/*   Updated: 2020/02/25 23:13:23 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char *p1;
	unsigned char *p2;

	p1 = (unsigned char *)dest;
	p2 = (unsigned char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (p1 > p2)
	{
		p1 = p1 + len;
		p2 = p2 + len;
		while (len--)
			*p1-- = *p2--;
	}
	else
	{
		while ((int)len--)
			*p1++ = *p2++;
	}
	return (dest);
}
