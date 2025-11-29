#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

char *gnl(int fd)
{
	char	*d;

	read(fd, d, 6);
	d[6] = '\0';
	write(1, d, 6);
	read(fd, d, 57);
	return (d);
}

int main()
{
	int	fd = open("text.txt", O_RDWR);

	// char	*d;

	// read(fd, d, 6);
	// d[6] = '\0';
	// write(1, d, 6);
	// read(fd, d, 57);
	char *d = gnl(fd);
	write(1, d, 57);
	close(fd);
}
