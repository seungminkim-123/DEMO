/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 02:06:00 by seukim            #+#    #+#             */
/*   Updated: 2020/03/29 02:06:00 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

# define FT_PRINTF_CHAR_FORMAT '%'

typedef struct s_ft_printf_settings
{
	int		written;
	char	*format;
	va_list		parameters;
	int		fd;
	int		end;
}				t_ft_printf_settings;

typedef struct s_ft_printf_flags
{
	char	letter;
	int		vaild;
	int		minus_sign_used;
	int		side;
	char	padding_char;
	int		width_enabled;
	int		width;
	int		width_negative;
	int		precision_enabled;
	int		precision;
	int		precision_negative;
	int		hashtag;
	int		hex_upper;
}			t_ft_printf_flags;

void	ft_printf_putchar(t_ft_printf_settings *settings, char c);
void	ft_printf_handle(t_ft_printf_settings *settings);
void	ft_printf_format(t_ft_printf_settings *settings, size_t *index);

#endif
