#include <fcntl.h>
#include "get_next_line_bonus.h"
#include <stdio.h>

int main()
{
	int fd = open("my.txt", O_RDONLY);
	char *line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
