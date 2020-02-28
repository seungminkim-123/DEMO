/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 05:22:06 by seukim            #+#    #+#             */
/*   Updated: 2020/02/27 05:22:06 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char *p1;
	char sym;

	p1 = (char*)str + ft_strlen(str);
	sym = (char)c;
	while (p1 >= str)
	{
		if (*p1 == sym)
			return (p1);
		p1--;
	}
	return ('\0');
}
