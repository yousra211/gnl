#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

// int main()
// {
// 	int	fd = open("text.txt", O_RDWR);

// 	write(fd, "21", 2);

// 	char	*d;

// 	read(fd, d, 6);
// 	d[6] = '\0';
// 	write(1, d, 6);
// 	read(fd, d, 57);
// 	write(1, d, 57);
// 	close(fd);
// }
int main()
{
	int	fd = open("text.txt", O_RDWR);

	char e[125];
	char d[62];
	int i = 0;

	read(fd, e, 124);
	read(fd, d, 61);
	d[61] = '\0';
	// while(e[i])
	// {
	// 	e[i]= toupper(e[i]);
	// 	write(1, &e[i], 1);
	// 	i++;
	// }
	close(fd);
	fd = open("text.txt", O_RDWR);
	read(fd, e, 124);
	// write(fd, "helloo",6);
	// printf("%s", d);
	while(d[i])
	{
		d[i]= toupper(d[i]);
		write(fd, &d[i], 1);
		i++;
	}
	close(fd);
}