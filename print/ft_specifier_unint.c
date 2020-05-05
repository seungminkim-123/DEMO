/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_unint.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 18:27:39 by seukim            #+#    #+#             */
/*   Updated: 2020/05/05 18:27:39 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_specifier_unint(t_flag_info *flaginfo, int *printlen)
{
	unsigned int	number;
	char *p1;
	ft_check_widthstar(flaginfo);
	ft_check_precisionstar(flaginfo);
	number = va_arg(flaginfo->args, unsigned int);
	p1 = ft_itoa(number);
	if ((flaginfo->precision - ft_strlen(p1)) > 0)
		p1 = ft_printf_strjoin(p1, flaginfo->precision - ft_strlen(p1));
	if (flaginfo->minus)
	{
		ft_putstr(p1, printlen);
		if (flaginfo->width)
			ft_number_width(flaginfo->width, ft_strlen(p1), number, printlen);
		return (1);
	}
	if (!(flaginfo->minus) && flaginfo->width > ft_strlen(p1) + 1)
		ft_print_number(flaginfo, p1, number, printlen);
	else
	{
		if (number < 0)
			ft_putchar('-', printlen);
		ft_putstr(p1, printlen);
	}
}
