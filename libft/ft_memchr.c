/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 03:57:38 by seukim            #+#    #+#             */
/*   Updated: 2020/04/07 03:57:38 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void	*ft_memchr(const void *ptr, int c, size_t n)
{
	unsigned char	value;
	unsigned char	*p1;
	int				i;

	i = 0;
	p1 = (unsigned char*)ptr;
	value = (unsigned char)c;
	while (n > i)
	{
		if (*p1 == value)
			return (ptr + i);
		p1++;
		i++;
	}
	return (NULL);
}
