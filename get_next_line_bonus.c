/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhamdaou <yhamdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 12:37:59 by yhamdaou          #+#    #+#             */
/*   Updated: 2025/12/04 13:34:33 by yhamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_read(int fd, char *string)
{
	int		byte;
	char	*str;
	char	*tmp;

	byte = 0;
	str = NULL;
	while (ft_strchr(str, '\n') != 1)
	{
		byte = read(fd, string, BUFFER_SIZE);
		if (byte == 0)
			break ;
		string[byte] = '\0';
		tmp = str;
		str = ft_strjoin(tmp, string);
		free(tmp);
	}
	if (!str)
		return (NULL);
	return (str);
}

static char	*ft_get_line(char *comb)
{
	char	*s;
	int		i;

	i = 0;
	if (!comb)
		return (NULL);
	i = 0;
	while (comb[i] && comb[i] != '\n')
		i++;
	if (comb[i] == '\n')
		(i)++;
	s = ft_substr(comb, 0, i);
	return (s);
}

static char	*ft_get_reste(char *comb)
{
	char	*s;
	int		i;

	i = 0;
	if (!comb)
		return (NULL);
	while (comb[i] && comb[i] != '\n')
		i++;
	if (comb[i] == '\n')
		i++;
	if (comb[i] == '\0')
		return (NULL);
	else
		s = ft_substr(comb, i, ft_strlen(comb) - i);
	return (s);
}

char	*ft_check(int fd, char **reste)
{
	if (fd >= 0 && fd < 10240)
	{
		free(reste[fd]);
		reste[fd] = NULL;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*str;
	char		*s;
	char		*comb;
	char static	*reste[10240];
	char		*string;

	if (fd < 0 || fd >= 10240 || read(fd, 0, 0) == -1 || BUFFER_SIZE < 0)
		return (ft_check(fd, reste));
	string = malloc(BUFFER_SIZE + 1);
	if (!string)
		return (NULL);
	str = ft_read(fd, string);
	free(string);
	comb = ft_strjoin(reste[fd], str);
	free(str);
	free(reste[fd]);
	s = ft_get_line(comb);
	reste[fd] = ft_get_reste(comb);
	free(comb);
	return (s);
}
