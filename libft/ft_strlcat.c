/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 19:09:20 by seukim            #+#    #+#             */
/*   Updated: 2020/02/26 19:09:20 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t i;
	unsigned char *p1;
	size_t dest_len;

	i = 0;
	p1 = (unsigned char*)dest;
	while (*p1 !='\0')
		p1++;
	while
}
