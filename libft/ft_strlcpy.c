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

	i = 0;
	char *sr = (char *)src;
	if (n > 0)
	{
		while (n - 1 > 0 && *sr !='\0')
		{
			*dest++ = *sr++;
			n--;
			i++;
		}
	}
	*dest = '\0';
	return (ft_strlen(sr));
}
