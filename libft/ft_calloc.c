/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 02:26:00 by seukim            #+#    #+#             */
/*   Updated: 2020/02/28 02:26:00 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *p1;
	size_t len;

	len = count * size;
	p1 = malloc(len);
	if (p1 == 0)
		return (NULL);
	while (len > 0)
	{
		*((char *)p1) = 0;
		p1++;
		len--;
	}
	return (0);
}
