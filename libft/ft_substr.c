/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 03:59:28 by seukim            #+#    #+#             */
/*   Updated: 2020/04/07 03:59:28 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str1, unsigned int start, size_t len)
{
	size_t		str1_len;
	int			i;
	char		*p1;

	i = 0;
	str1_len = ft_strlen(str1);
	if ((str1_len < start + len) || (str1[0] == '\0'))
		return (NULL);
	p1 = (char*)malloc(sizeof(char) * len + 1);
	while(len > 0)
	{
		p1[i] = str1[start++];
		i++;
		len--;
	}
	p1[i] = '\0';
	return (p1);
}
