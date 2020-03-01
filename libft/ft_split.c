/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 04:49:29 by seukim            #+#    #+#             */
/*   Updated: 2020/02/29 04:49:29 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_str(char *s1, char c)
{
	int		n_str;

	n_str = 0;
	while (*s1)
	{
		while (*s1 == c && *s1)
			s1++;
		if (*s1 != c && *s1)
			n_str++;
		while (*s1 != c && *s1)
			s1++;
	}
	return (n_str);
}

char	**ft_split(char *s1, char c)
{
	size_t s1_len;
	char	**res;
	size_t	i;
	size_t	k;

	k = 0;
	s1_len = count_str(s1,c);
	printf("%d",s1_len);printf("%d",s1_len);printf("%d",s1_len);
	return (c);
}

int main()
{
	char a[] = "12111221";
	char b = '2';
	printf("%c",ft_split(a,b));
}

