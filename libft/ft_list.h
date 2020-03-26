/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 23:28:08 by seukim            #+#    #+#             */
/*   Updated: 2020/03/25 23:28:08 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
#define FT_LIST_H

#include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(const void *content, size_t content_size);
#endif
