/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 19:01:32 by seukim            #+#    #+#             */
/*   Updated: 2020/03/28 19:01:32 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_flagsc(int *i, const char *str, va_list args, int *p)
{
	str[*i] == '-' ? flags_int(args, p) : 0;
	str[*i] == '0' ? flags_int(args, p) : 0;
	str[*i] == '.' ? flags_int(args, p) : 0;
	str[*i] == '*' ? flags_int(args, p) : 0;
	
}

void	parse_flags(int *i, const char *str, va_list args, int *p)
{
	*i = *i + 1;
	str[*i] == 'd' ? flags_int(args, p) : 0;
	str[*i] == 'i' ? flags_int (args, p) : 0;
	str[*i] == 'u' ? flags_uint(args, p) : 0;
	str[*i] == 's' ? flags_str(args, p) : 0;
	str[*i] == 'c' ? flags_char(args, p) : 0;
	str[*i] == 'p' ? flags_p(args, p) : 0;
	str[*i] == 'x' ? flags_hex(args, p) : 0;
	str[*i] == 'X' ? flags_bighex(args, p) : 0;
	str[*i] == '%' ? flags_per(p) : 0;
	parse_flagsc(i, str, args, p);
}