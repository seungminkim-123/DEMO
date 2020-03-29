/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 03:37:43 by seukim            #+#    #+#             */
/*   Updated: 2020/03/29 03:37:43 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_handle(t_ft_printf_settings *settings)
{
	size_t		index;
	unsigned	char	current;

	settings->end = 0;
	index = 0;
	while ((current = settings->format[index]) && !settings->end)

}
