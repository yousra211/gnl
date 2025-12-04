#include "get_next_line.h"

char *ft_read(int fd, char *string)
{
	int	byte;
	char *str;
	char *tmp;

	byte = 0;
	str = NULL;	
	while (ft_strchr(str, '\n') != 1)
	{
		byte = read(fd, string, BUFFER_SIZE);
		if (byte == 0)
			break;
		string[byte] = '\0';
		tmp = str;
		str = ft_strjoin(tmp, string);
		free(tmp);
	}
	if (!str)
		return NULL;
	return (str);
}

char *ft_get_line(char *comb)
{
	char	*s;
	int		i;

	i = 0;
	if (!comb)
		return (NULL);
	i = 0;
	while(comb[i] && comb[i] != '\n')
		i++;
	if (comb[i] == '\n')
		(i)++;
	s = ft_substr(comb, 0, i);
	return (s);
}

char *ft_get_reste(char *comb)
{
	char *s;
	int	i;

	i = 0;
	if (!comb)
		return (NULL);
	while(comb[i] && comb[i] != '\n')
		i++;
	if (comb[i] == '\n')
		(i)++;	
	if (comb[i] == '\0')
		return (NULL);
	else
		s = ft_substr(comb, i, ft_strlen(comb) - i);
	return (s);
}

char *get_next_line(int fd)
{
	char		*str;
	char		*s;
	char		*comb;
	char static	*reste;
	char		*string;

	if (fd < 0 || read(fd, 0, 0) == -1 || BUFFER_SIZE < 0)
	{
		free(reste);
		reste = NULL;
		return (NULL);
	}
	string = malloc(BUFFER_SIZE + 1);
	str = ft_read(fd, string);
	free(string);
	comb = ft_strjoin(reste, str);
	free(str);
	s = ft_get_line(comb);
	char	*tmp = reste;
	reste = ft_get_reste(comb);
	free(comb);
	free(tmp);
	return (s);
}

// void	f()
// {
// 	system("leaks -q a.out");
// }

int main(int ac, char **av)
{
	// atexit(f);
	int fd = open(av[1], O_RDONLY);

	char	*line = get_next_line(fd);
	// printf("%s", line);
	// line = get_next_line(fd);
	// printf("%s", line);
	// line = get_next_line(fd);
	// printf("%s", line);
	// line = get_next_line(fd);
	// printf("%s", line);  
	// line = get_next_line(fd);
	// printf("%s", line);  

	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
}