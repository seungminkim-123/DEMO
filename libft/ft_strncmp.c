/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 03:59:09 by seukim            #+#    #+#             */
/*   Updated: 2020/04/07 03:59:09 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strncmp(const char *str1, const char *str2, size_t n)
{
	char	*p1;
	char	*p2;

	p1 = (char *)str1;
	p2 = (char *)str2;
	while (n > 0 && *p1 != '\0' && p2 != '\0')
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		p2++;
		p1++;
		n--;
	}
	return (0);
}
