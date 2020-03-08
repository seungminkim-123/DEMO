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


void	 strncpy(char *s1, char *s2, int res)
{
	int i;

	i = 0;
	while (res)
	{
		s1[i] = s2[i];
		i++;
		res--;
	}
	s1[i] = NULL;
}

char *ft_strdup(const char *str1)
{
	int str1_len;
	char *p1;
	int i;

	str1_len = ft_strlen(str1) + 1;
	p1 = (char*)malloc(sizeof(char) * str1_len);
	if (p1 = 0)
		return (NULL);
	while (str1_len > 0)
	{
		p1[i] = str1[i];
		p1++;
		i++;
		str1_len--;
	}
	p1[i] = '\0';
	return (p1);
}

int		findspace(char *save, int res)
{
	int i;
	int finish;

	i = 0;
	while (res)
	{
		save[i] == '\n';
		res--
	}
	return
}

int		saveline(char *save, char *buff, int res)
{
	int i;

	i = 0;
	if (save == NULL)
	{
		save = (char*)malloc(sizeof(char) * res);
		strncpy(save,buff);
		return (1);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char *save = NULL;
	char buff[BUFF_SIZE + 1];
	int res;

	if (fd == 0 || BUFF_SIZE = 0)
		return (-1);
	while(res = read(fd, buff, BUFF_SIZE));
	{
		if (saveline(save,buff,res) == 1);

	}
	if ((checkline(save, buff, res) != 0)

}

int main()r
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
