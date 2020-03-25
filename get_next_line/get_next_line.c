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

#include "get_next_line.h"

int	ft_strlen(const char *src)
{
	int len;

	len = 0;
	while (*src++ != '\0')
		len++;
	return (len);
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

char	*ft_substr(char const *str1, unsigned int start, size_t len)
{
	size_t str1_len;
	int i;
	char *p1;

	i = 0;
	str1_len = ft_strlen(str1);
	if ((str1_len < start + len) || (str1[0] == '\0'))
		return (NULL);
	p1 = (char*)malloc(sizeof(char) * len + 1);
	while(len > 0)
	{
		p1[i] = str1[start++];
		i++;
		len--;
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
	char *tmp;
	int i;

	i = 0;
	while (save[i] != '\n' && save[i] != '\0')
		i++;
	if (save[i] == '\n')
	{
		*line = ft_substr(save, 0, i);
		tmp = ft_strdup(save[i + 1]);
		free(save);
		save = tmp;
	}
	else if(save[i] == '\0')
	{
		*line = ft_substr(save, 0, i);
	}
	return (1);
}

int output(char *save, int res, char **line)
{
	if (res < 0)
		return (-1);
	if (res == 0 && save == NULL)
		return (0);
	if (res > 0)
		return (getline(save,line));
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
		if (save == NULL)
			save = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(save,buff);
			free(save);
			save = tmp;
		}
		if (ft_strchr(save, 10))
			break ;
	}
	return (output(save, res, line));
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
	}
	return 0;
}
