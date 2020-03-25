/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 04:35:20 by seukim            #+#    #+#             */
/*   Updated: 2020/03/16 04:35:20 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_flag(char c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0')
		return (1);
	return (0);
}

int	is_width(char c)
{
	if ((c >= '0' && c <= '9') || c == '*')
		return (1);
	return (0);
}

int	is_preci(char c)
{
	if (c == '.')
		return (1);
	return (0);
}

int	is_length(char c)
{
	if (c == 'h' || c == 'l' || c == 'j' || c == 'z')
		return (1);
	return (0);
}

int	is_speci(char c)
{
	if (c == '%' || c == 's' || c == 'S' || c == 'p' || c == 'd' ||
			c == 'D' || c == 'i' || c == 'o' || c == 'O' || c == 'u' ||
			c == 'U' || c == 'x' || c == 'X' || c == 'c' || c == 'C' ||
			c == 'P' || c == 'b' || c == 'I' || c == 'B')
		return (1);
	return (0);
}