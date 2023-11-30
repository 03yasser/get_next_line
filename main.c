#include "get_next_line.h"

int main()
{

	char *str;
	int fd1 = open ("tst1", O_RDONLY);
	char *buffer;
	
	for (int i = 0; i < 10 ; i++)
	{
		str = get_next_line(fd1);
		printf ("[%s]", str);
		free (str);
	}
	close (fd1);
}