/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 00:50:17 by seukim            #+#    #+#             */
/*   Updated: 2020/03/12 00:50:17 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>


/*%[flags] [width] [.precision] [lengh [서식지정자]]
일단 format으로 들어온 문자열의상태가 괜찮은지확인 .
slack에보니 일단 인자가 유효관지확인을하라고는하는데.. 일단 따로만들면 될거같음

이후에 %찾고 그전까지 는 write %이 없으면 리턴
get current characters
지시자 옵션 체크
conversion 처리한것 write
위에 무한 반복

이렇게하라는데 흠 일단 %끝날때 포인터옮겨서 format이 NULL일떄까지 반복문넣어주면 될듯함.

*/

struct str_info{
	int flag;
	int width;
	int lens;
	int preci;
	char speci;
}
int		ft_printf(const char *format, ...)
{
	int i;
	i = 0;
	if (!format)
		return (0);
	i = check(format);
	return (0);
}

int main()
{
	int a;
	a = 1;
	a = ft_printf(a);
	return (0);
}
