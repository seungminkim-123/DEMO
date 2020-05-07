/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_unint.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 18:27:39 by seukim            #+#    #+#             */
/*   Updated: 2020/05/07 17:26:43 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		itoa_length_u(unsigned int n)
{
	int		len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa_u(unsigned int n)
{
	char	*p1;
	int		len;

	len = itoa_length_u(n);
	if(!(p1 = (char *)malloc(sizeof(p1) * len + 1)))
		return (NULL);
	p1[itoa_length_u(n)] = '\0';
	if (n == 0)
	{
		p1[0] = '0';
		return (p1);
	}
	while (n != 0 && len >= 0)
	{
		p1[len-- - 1] = n % 10 + 48;
		n = n / 10;
	}
	return (p1);
}

int		ft_specifier_unint(t_flag_info *flaginfo, int *printlen)
{
	unsigned int	number;
	char			*p1;

	ft_check_widthstar(flaginfo);
	ft_check_precisionstar(flaginfo);
	number = va_arg(flaginfo->args, unsigned int);
	p1 = ft_itoa_u(number);
	if ((flaginfo->precision - ft_strlen(p1)) > 0)
		p1 = ft_printf_strjoin(p1, flaginfo->precision - ft_strlen(p1));
	if (flaginfo->precision == 0 && number == 0 && flaginfo->dot)
	{
		while (flaginfo->width-- > 0)
			ft_putchar(' ', printlen);
		return (1);
	}
	number = 1;
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
		if ((flaginfo->width - ft_strlen(p1)) == 1 && number >= 0)
		{
			if (flaginfo->zero)
				ft_putchar('0', printlen);
			else
				ft_putchar(' ', printlen);
		}
		ft_putstr(p1, printlen);
	}
	return (1);
}
