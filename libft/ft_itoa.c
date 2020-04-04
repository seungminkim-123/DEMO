/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 23:16:39 by seukim            #+#    #+#             */
/*   Updated: 2020/03/02 23:16:39 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	itoa_length(int n)
{
	int len;

	len = 0;
	if (n < 0)
		len++;
	if (n == 0)
		len = 1;
	while (n)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*p1;
	int		len;

	len = itoa_length(n);
	if(!(p1 = (char *)malloc(sizeof(p1) * len + 1)))
		return (NULL);
	if (n == 0)
		p1[0] = '0';
	if (n < 0)
	{
		p1[0] = '-';
		if (n == -2147483648)
		{
			p1[len-- -1] = '8';
			n = n / 10;
		}
		n = -n;
	}
	while (n != 0 && len >= 0)
	{
		p1[len-- - 1] = n % 10 + 48;
		n = n / 10;
	}
	p1[itoa_length(n)] = '\0';
	return (p1);
}
