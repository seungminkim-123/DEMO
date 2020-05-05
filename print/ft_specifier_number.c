/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_number.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 20:26:39 by seukim            #+#    #+#             */
/*   Updated: 2020/04/28 20:26:39 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_number(char c, int *printlen)
{
	write(1, &c, 1);
	*printlen += 1;
}

int		ft_putstr(char *str, int *printlen)
{
	int i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		ft_putchar(str[i], printlen);
		i++;
	}
	return (0);
}

static	int		itoa_length(int n)
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

char	*ft_itoa(size_t n)
{
	char	*p1;
	int		len;

	len = itoa_length(n);
	if(!(p1 = (char *)malloc(sizeof(p1) * len + 1)))
		return (NULL);
	p1[itoa_length(n)] = '\0';
	if (n == 0)
		p1[0] = '0';
	if (n < 0)
	{
		if (n == -2147483648)
		{
			p1[len-- -1] = '8';
			n = n / 10;
		}
		n = -n;
	}
	while (n != 0 && len >= 0)
	{
		p1[len-- - 1] = n % 10 + 48;
		n = n / 10;
	}
	return (p1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p1;
	char	*p2;

	if (!s1 && !s2)
		return (NULL);
	p1 = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (p1 == 0)
		return (NULL);
	p2 = p1;
	while (*s1 != '\0')
		*p1++ = *s1++;
	while (*s2 != '\0')
		*p1++ = *s2++;
	*p1 = '\0';
	return (p2);
}

char	*ft_printf_strjoin(char *str, int i)
{
	char	*p1;
	char	*p2;
	int		j;

	j = 0;
	p1 = (char*)malloc(sizeof(char) * i + 1);
	while (i)
	{
		p1[j++] = '0';
		i--;
	}
	p1[j] = '\0';
	p2 = ft_strjoin(p1, str);
	free(p1);
	free(str);
	return (p2);
}

void	ft_check_precisionstar(t_flag_info *flaginfo)
{
	if (flaginfo->starprecision)
		flaginfo->precision = va_arg(flaginfo->args, int);
	if (flaginfo->dot)
	{
		flaginfo->zero = 0;
	}
}

void		ft_number_width(int width, int minus, int number, int *printlen)
{
	if (number < 0)
		width--;
	while (width - minus > 0)
	{
		ft_putchar(' ', printlen);
		width--;
	}
}

void	ft_print_number(t_flag_info *flaginfo, char *p1, int number,
			int *printlen)
{
	if (flaginfo->minus && number < 0)
		ft_putchar('-', printlen);
	if (flaginfo->zero && number < 0)
	{
		ft_putchar('-',printlen);
		flaginfo->width--;
	}
	while (flaginfo->width - ft_strlen(p1) > 1)
	{
		if (flaginfo->zero)
			ft_putchar('0', printlen);
		else
			ft_putchar(' ', printlen);
		if ((flaginfo->width - ft_strlen(p1)) == 2)
		{
			if (number < 0 && !(flaginfo->zero))
			{
				ft_putchar('-', printlen);
				flaginfo->width--;
			}
			else
			{
				if (flaginfo->zero)
					ft_putchar('0', printlen);
				else
					ft_putchar(' ', printlen);
				flaginfo->width--;
			}
		}
		flaginfo->width--;
	}
	ft_putstr(p1, printlen);
}

int		ft_specifier_number(t_flag_info	*flaginfo, int *printlen)
{
	int number;
	int		i;
	char *p1;

	ft_check_widthstar(flaginfo);
	ft_check_precisionstar(flaginfo);
	number = va_arg(flaginfo->args, int);
	p1 = ft_itoa(number);
	if ((flaginfo->precision - ft_strlen(p1)) > 0)
		p1 = ft_printf_strjoin(p1, flaginfo->precision - ft_strlen(p1));
	if (flaginfo->minus)
	{
		if (number < 0)
			ft_putchar('-', printlen);
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
	return (i);
}
