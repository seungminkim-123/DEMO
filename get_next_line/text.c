
#include <fcntl.h>
#include <stdio.h>

int main()
{
	char	buff[1000];
	int    fd;
	int   res;
	char  *str;

	if (( fd = open( "./test.txt", O_RDONLY)))
	{
		str = &buff[0];
		res = read( fd, buff,3);
		printf("%s\n",buff);
		printf("%d\n",res);
		res = read( fd, buff,3);
		printf("%s\n",buff);
		printf("%d\n",res);
		res = read( fd, buff,3);
		printf("%s\n",buff);
		printf("%d\n",res);
	}
	return 0;
}
