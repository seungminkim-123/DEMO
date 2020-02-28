/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 04:55:03 by seukim            #+#    #+#             */
/*   Updated: 2020/02/26 04:55:03 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int c, size_t n)
{
	unsigned char value;
	unsigned char *p1;

	p1 = (unsigned char*)ptr;
	value = (unsigned char)c;
	while (n > 0)
	{
		if (*p1 == value)
			return (p1);
		p1++;
		n--;
	}
	return (NULL);
}