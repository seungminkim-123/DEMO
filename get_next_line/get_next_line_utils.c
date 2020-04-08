/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 12:52:29 by seukim            #+#    #+#             */
/*   Updated: 2020/03/11 12:52:29 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *str1)
{
	int		str1_len;
	char	*p1;
	int		i;

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

char	*ft_substr(char const *str1, unsigned int start, size_t len)
{
	size_t	str1_len;
	int		i;
	char	*p1;

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p1;
	char	*p2;

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

size_t		ft_strlen(const char *src)
{
	size_t	len;

	len = 0;
	while (*src++ != '\0')
		len++;
	return (len);
}
