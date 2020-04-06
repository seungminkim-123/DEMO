/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 03:59:03 by seukim            #+#    #+#             */
/*   Updated: 2020/04/07 03:59:03 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char *p1;
	int i;

	i = 0;
	if (s && f)
	{
		if (!(p1 =(char *)malloc(sizeof(p1) * strlen((char *)s) + 1)))
			return (NULL);
		while (s[i] != '\0')
		{
			p1[i] = f(i,s[i]);
			i++;
		}
		return (p1);
	}
	return (NULL);
}
