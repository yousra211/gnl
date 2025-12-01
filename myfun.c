#include "get_next_line.h"

char *get_next_line(int fd)
{
	int	byte;
	char *string;
	char *str;
	char *tmp;

	byte = 0;
	string = NULL;
	str = NULL;	
	while (ft_strchr(str, '\n') != 1)
	{
		string = malloc(BUFFER + 1);
		byte = read(fd, string, BUFFER);
		if (byte == 0)
		{
			free(string);
			break;
		}
		string[byte] = '\0';
		tmp = str;
		str = ft_strjoin(tmp, string);
		free(tmp);
	}
	if (!str)
		return NULL;
}
