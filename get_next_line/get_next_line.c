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
#include <stdlib.h>

size_t	ft_strlen(const char *src)
{
	size_t len;

	len = 0;
	while (*src++ != '\0')
		len++;
	return (len);
}


void	 ft_strncpy(char *s1, char *s2, int res)
{
	int i;

	i = 0;
	while (res)
	{
		s1[i] = s2[i];
		i++;
		res--;
	}
	s1[i] = '\0';
}

char *ft_strdup(const char *str1)
{
	int str1_len;
	char *p1;
	int i;

	str1_len = ft_strlen(str1) + 1;
	p1 = (char*)malloc(sizeof(char) * str1_len);
	if (p1 == 0)
		return (NULL);
	while (str1_len > 1)
	{
		p1[i] = str1[i];
		p1++;
		i++;
		str1_len--;
	}
	p1[i] = '\0';
	return (p1);
}

char *ft_strjoin(char const *s1, char const *s2)
{
	char *p1;
	char *p2;

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

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char*)s);
		s++;
	}
	if (*s == c)
		return ((char*)s);
	return (NULL);
}

int getline(char *save, char **line)
{
	char tmp;
	int i;

	i = 0;
	while (save[i] != '\n' && save[i] != '\0')
		i++;
	if (save[i] == '\n')
	{
		*line = ft_strsub(save, 0, i);
		tmp = ft_strdup(save[i + 1]);
		free(save);
		save = tmp;
	}
	else if(save[i] == '\0')
	{
		*line = ft_strsub(save, 0, i);
	}
	return (1);

}

int output(char *save, int res, char **line)
{
	if (res < 0)
		return (-1);
	if (res == 0 && save == NULL)
		return (0)
	if (res > 0)
		return (getline(save,line));)
}

int		get_next_line(int fd, char **line)
{
	static char *save;
	char buff[BUFF_SIZE + 1];
	char *tmp;
	int res;

	if (fd == 0 || BUFF_SIZE = 0)
		return (-1);
	while ((res = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[res] = '\0';
		if (save = NULL)
			save = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(save,buff);
			free(save);
			save = tmp;
		}
		if (ft_strchr(save, '/n'))
			break ;
	}
	return (output);
}

int main()
{
	char	buff[22];
	int    fd;
	int   res;
	char  *str;
	char **line;

	if (( fd = open( "./test.txt", O_RDONLY)))
	{
		get_next_line(fd, line);
	return 0;
}
