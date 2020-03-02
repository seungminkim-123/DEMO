/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 04:32:59 by seukim            #+#    #+#             */
/*   Updated: 2020/02/27 04:32:59 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*p1;
	char	sym;

	sym = (char)c;
	p1 = (char*)str;
	while (*p1 != '\0')
	{
		if (*p1 == sym)
			return (p1);
		p1++;
	}
	if (*p1 == sym)
		return(p1);
	return (NULL);
}
