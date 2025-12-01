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

char *ft_gnl(int fd)
{
	char string[2];
	string[0] = '\0';
	char *str = NULL;
	while (ft_strchr(str, '\n') != 1)
	{
		read(fd, string, 1);
		string[1] = '\0';
		str = ft_strjoin(str, string);
	}
	return(str);
}

// int main()
// {
// 	int fd = open("my.txt",O_RDWR);
// 	char *s = ft_gnl(fd);
// 	write(1, s, ft_strlen(s));
// 		char *s1 = ft_gnl(fd);
// 	write(1, s1, ft_strlen(s1));
// 	// int i = 0;
// 	// while (i < ft_strlen(s))
// 	// {
// 	// 	write(1, &s[i], 1);
// 	// 	i++;
// 	// }
// 	close(fd);
// }