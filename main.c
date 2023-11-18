#include "get_next_line.h"

int main()
{

	char *str;
	int fd = open ("tst", O_RDONLY);
	// for (int i = 0; i < 5; i++)
	// {
	// 	str = get_next_line(fd);
	// 	//printf("[%s]\n", str);
	// 	free (str);
	// }
	char *buffer;
	
	for (int i = 0; i < 4 ; i++)
	{
		buffer = calloc (BUFFER_SIZE,1);
		int bytes = read (fd, buffer, BUFFER_SIZE);
		printf ("[%d][%s]\n",bytes, buffer);
		free(buffer);
	}
	close (fd);
}