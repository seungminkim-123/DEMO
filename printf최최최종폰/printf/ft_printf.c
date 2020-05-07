/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 21:10:47 by seukim            #+#    #+#             */
/*   Updated: 2020/05/07 18:09:18 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		find_parse_length(const char *format, int i, t_flag_info *flaginfo)
{
	int				length;

	length = 0;
	while (1)
	{
		if (format[i] == '%')
			break ;
		if (ft_strchr(conversion,format[i]))
		{
			flaginfo->specifier = format[i];
			break ;
		}
		i++;
		length++;
	}
	return (length);
}


int		ft_combine_option(t_flag_info *flaginfo, int *printlen)
{
	int				i;

	i = 0;
	if (flaginfo->specifier == 'c')
		ft_specifier_char(flaginfo, printlen);
	if (flaginfo->specifier == 'd' || flaginfo->specifier == 'i')
		ft_specifier_number(flaginfo, printlen);
	if (flaginfo->specifier == 's')
		ft_specifier_string(flaginfo, printlen);
	if (flaginfo->specifier == 'p')
		ft_specifier_pointer(flaginfo, printlen);
	if (flaginfo->specifier == 'x')
		ft_specifier_hexa(flaginfo, printlen);
	if (flaginfo->specifier == 'X')
		ft_specifier_bighexa(flaginfo, printlen);
	if (flaginfo->specifier == 'u')
		ft_specifier_unint(flaginfo, printlen);
	if (flaginfo->specifier == '%')
		ft_specifier_persentage(flaginfo, printlen);
	return (1);
}

int		ft_flag_parse(const char *format, int i,
				t_flag_info *flaginfo, int *printlen)
{
	int				parse_length;
	char			*save;

	reset_flag(flaginfo);
	i += 1;
	parse_length = find_parse_length(format, i, flaginfo);
	if ((save = ft_substr(format, i, parse_length + 1)) > 0)
		set_flag_option(flaginfo, save);
	free(save);
	if (ft_combine_option(flaginfo, printlen))
		return (i + parse_length);
	return (-1);
}

int		ft_printf(const char *format, ...)
{
	int				i;
	t_flag_info		flaginfo;
	int				printlen;

	printlen = 0;
	va_start(flaginfo.args, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			ft_putchar(format[i], &printlen);
		}
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i = ft_flag_parse(format, i, &flaginfo, &printlen);
			if (i == -1)
				return (-1);
		}
		i++;
	}
	return (printlen);
}
