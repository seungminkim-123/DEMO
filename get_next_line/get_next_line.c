/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:18:44 by seukim            #+#    #+#             */
/*   Updated: 2020/03/05 17:18:44 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int main()
{
   char   buff[BUFF_SIZE];
   int    fd;

   if ( 0 < ( fd = open( "./test.txt", O_RDONLY)))
   {
      read( fd, buff, BUFF_SIZE);
      puts( buff);
      close( fd);
   }
   else
   {
      printf( "파일 열기에 실패했습니다.\n");
   }
   return 0;
}
