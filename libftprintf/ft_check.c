/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 23:31:24 by seukim            #+#    #+#             */
/*   Updated: 2020/03/14 23:31:24 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>


void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int check_option(char *format, int i)
{

}

int check(char *format)
{
	int i;

	i = 0;
	while (format[i] != '\0')
	{
		ft_putchar(format[i]);
		if (format[i] == '%')
			return(1);
		i++;
	}
	return (0);

}

