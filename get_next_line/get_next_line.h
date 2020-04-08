/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:19:42 by seukim            #+#    #+#             */
/*   Updated: 2020/03/05 17:19:42 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 4

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>

int		get_next_line(int fd, char **line);
int		output(char *save, int res, char **line);
int		getlinea(char *save, char **line);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *str1, unsigned int start, size_t len);
char	*ft_strdup(const char *str1);

#endif
