/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:04:03 by seukim            #+#    #+#             */
/*   Updated: 2020/02/26 15:04:03 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcpy(char *dest, const char *src, size_t n)
{
	unsigned int i;
	unsigned int j;
	unsigned int count;

	j = 0;
	while(*src != '\0')
	{
		j++;
		src++;
	}
	i = 0;
	if (n != 0)
	{
		while (src[i] != '\0' && n > 1)
		{
			dest[i] = src[i];
			i++;
			n--;
		}
		dest[i] = '\0';
	}
	return (j);
}
