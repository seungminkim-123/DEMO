/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 03:16:47 by seukim            #+#    #+#             */
/*   Updated: 2020/03/08 03:16:47 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>

int main()
{
	char	buff[22];
	int    fd;
	int   res;
	char  *str;

	if (( fd = open( "./test.txt", O_RDONLY)))
	{
		str = buff[0];
		res = read( fd, buff,7);
		printf("%s\n",buff);
		res = read( fd, buff,7);
		printf("%s\n",buff);
		res = read( fd, buff,7);
		printf("%s\n",buff);
		printf("%d\n",res);
	}
	return 0;
}
