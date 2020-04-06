/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 03:59:15 by seukim            #+#    #+#             */
/*   Updated: 2020/04/07 03:59:15 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *dest, const char *src, size_t n)
{
	char	*p1;
	char	*p2;
	size_t	i;

	p1 = (char *)dest;
	p2 = (char *)src;
	i = 0;
	if (src == 0)
		return ((char)dest);
	while (*dest != '\0' && n > 0)
	{
		p1 = (char *)dest;
		i = 0;
		while (*p1 != '\0' && *p1++ == *p2++)
		{
			i++;
			if (ft_strlen(src) == i)
				return (p1 - i);
		}
		p2 = (char *)src;
		dest++;
		n--;
	}
	return ('\0');
}
