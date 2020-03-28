/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 18:39:17 by seukim            #+#    #+#             */
/*   Updated: 2020/03/28 18:39:17 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list args;
	int		i;
	int		p;

	i = 0;
	p = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			parse_flags(&i, str, args, &p);
		else
			write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (p);
}