/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 03:41:35 by seukim            #+#    #+#             */
/*   Updated: 2020/05/01 03:41:35 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strdup(const char *str1)
{
	int		str1_len;
	char	*p1;
	int		i;

	i = 0;
	str1_len = ft_strlen(str1) + 1;
	p1 = (char*)malloc(sizeof(char) * str1_len);
	if (p1 == 0)
		return (NULL);
	while (str1_len > 1)
	{
		p1[i] = str1[i];
		i++;
		str1_len--;
	}
	p1[i] = '\0';
	return (p1);
}

char	*ft_set_stringprecision(t_flag_info *flaginfo, char *p1, int *printlen)
{
	char	*tmp;
	if (flaginfo->dot && flaginfo->precision == 0)
	{
		free(p1);
		p1 = NULL;
		return (p1);
	}
	if ((ft_strlen(p1) - flaginfo->precision) > 0)
	{
		tmp = ft_substr(p1, 0, flaginfo->precision);
		free(p1);
		p1 = tmp;
	}
	if (p1 == NULL)
	{
		p1 = ft_strdup("(null)");
	}
	return (p1);
}

int		ft_specifier_string(t_flag_info	*flaginfo, int *printlen)
{
	char *p1;
	int		i;

	i = 0;
	ft_check_widthstar(flaginfo);
	ft_check_precisionstar(flaginfo);
	p1 = va_arg(flaginfo->args, char*);
	if (flaginfo->dot || p1 == NULL)
		p1 = ft_set_stringprecision(flaginfo, p1, printlen);
	if (flaginfo->minus)
		ft_putstr(p1, printlen);
	ft_width(flaginfo->width, ft_strlen(p1), flaginfo->zero, printlen);
	if (!(flaginfo->minus))
		ft_putstr(p1, printlen);
	free(p1);
	return (0);
}
