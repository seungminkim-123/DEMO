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

int		getlinea(char *save, char **line)
{
	char	*tmp;
	int		i;

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

int		output(char *save, int res, char **line)
{
	if (res < 0)
		return (-1);
	if (res == 0 && save == NULL)
		return (0);
	if (res > 0)
		return (getlinea(save,line));
}

int		get_next_line(int fd, char **line)
{
	static char	*save;
	char		buff[BUFF_SIZE + 1];
	char		*tmp;
	int			res;

	if (fd == 0 || BUFF_SIZE == 0)
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
		printf("%s", *line);
	}
	return 0;
}
