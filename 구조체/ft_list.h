/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 02:33:23 by seukim            #+#    #+#             */
/*   Updated: 2020/03/24 02:33:23 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H
#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	struct	s_list		*next;
	void	*date;
}	t_list;

t_list			*ft_create_elem(void *data);

#endif
