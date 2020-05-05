/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 21:10:47 by seukim            #+#    #+#             */
/*   Updated: 2020/04/19 21:10:47 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	ft_putchar(char c, int *printlen)
{
	write(1, &c, 1);
	*printlen += 1;
}

int	ft_strlen(const char *src)
{
	int len;

	if (src == NULL)
		return (0);
	len = 0;
	while (*src++ != '\0')
		len++;
	return (len);
}

int		ft_atoi(char *str)
{
	int	i;
	int value;
	int result;

	value = 1;
	result = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
			i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			value = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] -'0');
		i++;
	}
	return ((int)result * value);
}

char    *ft_substr(char const *str1, unsigned int start, int len)
 {
	int		str1_len;
	int			i;
	char*p1;

	i = -1;
	str1_len = ft_strlen(str1);
	if ((str1_len < start) || len == 0)
	{
 		if (!(p1 = (char*)malloc(sizeof(char) * 1)))
 		return (0);
 		p1[0] = '\0';
 		return (p1);
 	}
 	if (!(p1 = (char*)malloc(sizeof(char) * (len + 1))))
 		return (0);
 	while (len > 0 && str1[start] != '\0')
 	{
 		p1[++i] = str1[start++];
 		len--;
 	}
 	p1[++i] = '\0';
 	return (p1);
}

char	*ft_strchr(const char *str, int c)
{
	char	*p1;
	char	sym;

	sym = (char)c;
	p1 = (char*)str;
	while (*p1 != '\0')
	{
		if (*p1 == sym)
			return (p1);
		p1++;
	}
	if (*p1 == sym)
		return(p1);
	return (0);
}











int		find_parse_length(const char *format, int i, t_flag_info *flaginfo)
{
	int length;

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

void	flag_parse_specifier(t_flag_info *flaginfo, char *save, int i)
{
	if (save[i] == '*')
	{
		flaginfo->starprecision = 1;
		i++;
	}
	if (ft_strchr(conversion, save[i]))
	{
		flaginfo->specifier = save[i];
	}
}

void	flag_parse_precision(t_flag_info *flaginfo, char *save, int i)
{
	int j;

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
	if (save[i] == '*')
	{
		flaginfo->starprecision = 1;
		i++;
	}
	flag_parse_specifier(flaginfo, save, i);
}

void	set_flag_option(t_flag_info *flaginfo, char *save)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (save[i] == '0')
	{
		flaginfo->zero = 1;
		i++;
	}
	if (save[i] == '-')
	{
		flaginfo->minus = 1;
		i++;
	}
	if (save[i] == '*')
	{
		flaginfo->starwidth = 1;
		i++;
	}
	flag_parse_precision(flaginfo, save, i);
}


int		ft_combine_option(t_flag_info *flaginfo, int *printlen)
{
	int i;

	i = 0;
	if (flaginfo->specifier == 'c')
		ft_specifier_char(flaginfo, printlen);
	if (flaginfo->specifier == 'd')
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
	if (save = ft_substr(format, i, parse_length + 1))
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

int main()
{
	char z;
	int i;
	char a;
	int j;

	j = 0;
	a = '\n';
	i = 0;
	z = 'z';
	i = ft_printf("%%%d\n",123);
	j = printf("%%\n");
	printf(" return ==%d\n", i);
	printf(" return ==%d", j);

}
