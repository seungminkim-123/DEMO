/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 19:12:44 by seukim            #+#    #+#             */
/*   Updated: 2020/02/28 19:12:44 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *str1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*new;

	if (!str1 || !set)
		return (NULL);
	start = 0;
	while (str1[start] && ft_strchr(set, str1[start]))
		start++;
	end = ft_strlen(str1 + start);
	if (end)
		while (str1[end + start - 1] != 0 &&
			 ft_strchr(set, str1[end + start - 1]) != 0)
			end--;
	if (!(new = malloc(sizeof(char) * end + 1)))
		return (NULL);
	ft_strlcpy(new, str1 + start, end);
	new[end] = 'NULL';
	return (new);
}
