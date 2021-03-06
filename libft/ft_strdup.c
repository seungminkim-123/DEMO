/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 03:58:35 by seukim            #+#    #+#             */
/*   Updated: 2020/04/07 03:58:35 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *str1)
{
	int		str1_len;
	char	*p1;
	int		i;

	i = 0;
	str1_len = ft_strlen(str1) + 1;
	p1 = (char*)malloc(sizeof(char) * str1_len);
	if (p1 == 0)
		return (NULL);
	while (str1_len > 1)
	{
		p1[i] = str1[i];
		p1++;
		i++;
		str1_len--;
	}
	p1[i] = '\0';
	return (p1);
}
