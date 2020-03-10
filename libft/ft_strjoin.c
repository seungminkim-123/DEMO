/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 17:33:34 by seukim            #+#    #+#             */
/*   Updated: 2020/02/28 17:33:34 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
	char *p1;
	char *p2;

	if (!s1 && !s2)
		return (NULL);
	p1 = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (p1 == 0)
		return (NULL);
	p2 = p1;
	while (*s1 != '\0')
		*p1++ = *s1++;
	while (*s2 != '\0')
		*p1++ = *s2++;
	*p1 = '\0';
	return (p2);
}
