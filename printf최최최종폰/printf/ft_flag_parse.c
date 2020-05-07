/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 19:14:47 by seukim            #+#    #+#             */
/*   Updated: 2020/05/07 19:14:47 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reset_flag(t_flag_info	*flaginfo)
{
	flaginfo->flag = 0;
	flaginfo->minus = 0;
	flaginfo->width = 0;
	flaginfo->dot = 0;
	flaginfo->precision = 0;
	flaginfo->specifier = 0;
	flaginfo->zero = 0;
	flaginfo->starwidth = 0;
	flaginfo->starprecision = 0;
}

void	set_flag_option(t_flag_info *flaginfo, char *save)
{
	int		i;

	i = 0;
	while (save[i] == '0' || save[i] == '-')
	{
		while (save[i] == '0')
		{
			flaginfo->zero = 1;
			i++;
		}
		while (save[i] == '-')
		{
			flaginfo->minus = 1;
			i++;
		}
	}
	if (save[i] == '*')
	{
		flaginfo->starwidth = 1;
		i++;
	}
	flag_parse_precision(flaginfo, save, i);
}

int		flag_parse_starprecision(t_flag_info *flaginfo, char *save, int i)
{
	if (save[i] == '*')
	{
		flaginfo->starprecision = 1;
		i++;
	}
	return (i);
}

void	flag_parse_specifier(t_flag_info *flaginfo, char *save, int i)
{
	if (save[i] == '*')
	{
		flaginfo->starprecision = 1;
		i++;
	}
	if (ft_strchr(conversion, save[i]))
		flaginfo->specifier = save[i];
}

void	flag_parse_precision(t_flag_info *flaginfo, char *save, int i)
{
	int		j;

	j = 0;
	while (save[i] >= '0' && save[i] <= '9')
	{
		if (j++ == 0)
			flaginfo->width = ft_atoi(&save[i]);
		i++;
	}
	j = 0;
	if (save[i] == '.')
	{
		flaginfo->dot = 1;
		i++;
	}
	while (save[i] >= '0' && save[i] <= '9')
	{
		if (j++ == 0)
			flaginfo->precision = ft_atoi(&save[i]);
		i++;
	}
	flag_parse_starprecision(flaginfo, save, i);
	flag_parse_specifier(flaginfo, save, i);
}
