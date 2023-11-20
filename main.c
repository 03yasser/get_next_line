#include "get_next_line_bonus.h"

int main()
{

	char *str;
	int fd1 = open ("tst1", O_RDONLY);
	int fd2 = open ("tst2", O_RDONLY);
	char *buffer;
	
	for (int i = 0; i < 2 ; i++)
	{
		str = get_next_line(fd1);
		printf ("[%s]", str);
		free (str);
	}
	printf ("\n");
	for (int i = 0; i < 4; i++)
	{
		str = get_next_line(fd2);
		printf ("[%s]", str);
		free (str);
	}
	close (fd1);
	close (fd2);
}