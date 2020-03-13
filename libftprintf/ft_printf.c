/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 00:50:17 by seukim            #+#    #+#             */
/*   Updated: 2020/03/12 00:50:17 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	t_flag	tab;
	size_t	i;
	char	*var;

	i = 0;
	va_start(ap, format);
	init_tab(&tab);
	var = NULL;
	while (format[i] != '\0' && tab.ret != -1)
		if (format[i] == '%' && format[i++])
		{
			if (!(var = ft_check((char *)format, &i, &tab, &ap)))
				return (-1);
			reinit_tab(&tab);
			tab.save_i = tab.i;
			free(var);
		}
		else
			ft_ret(&tab, format[i++]);
	(tab.buff[0] != '\0') ? ft_display(&tab) : 0;
	va_end(ap);
	return (tab.ret);
}

int main()
{
	int a;
	a = 1;
	printf("%c", a);
}
