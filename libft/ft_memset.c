/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 03:58:00 by seukim            #+#    #+#             */
/*   Updated: 2020/04/07 03:58:00 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void	*ft_memset(void *prt, int value, size_t num)
{
	unsigned char	*p1;
	unsigned char	insert;
	int				i;

	insert =(unsigned char)value;
	p1 = (unsigned char *)prt;
	i = 0;
	while (num > 0)
	{
		p1[i] = insert;
		num--;
		i++;
	}
	return (prt);
}
