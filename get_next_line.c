/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhamdaou <yhamdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 11:45:22 by yhamdaou          #+#    #+#             */
/*   Updated: 2025/12/01 22:48:19 by yhamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

char *get_next_line(int fd)
{
	int i = 0;
	int buffer = 77;
	char s1[2];
	char *s = NULL;
	static char *reste = NULL;
	char *comb = NULL;
	int byte = 0;
	
	char *string = NULL;
	char *str = NULL;
	int k = 0;
	if (ft_strchr(reste, '\n') == 1)
	{
		if (reste[0] == '\n')
		{
			s = ft_strdup(reste);
			reste = NULL;
			return (s);
		}
		while (reste[k] != '\n')
		{
			s1[0] = reste[k];
			s1[1] = '\0';
			s = ft_strjoin(s, s1);
			k++;
		}
		// for the \n
		s1[0] = reste[k];
		s1[1] = '\0';
		s = ft_strjoin(s, s1);
		k++;
		while(reste[k])
		{
			reste[i] = reste[k];
			i++;
			k++;
		}
		reste[i] = '\0';
		return (s);
	}
	
	while (ft_strchr(str, '\n') != 1)
	{
		string = malloc(buffer + 1);
		byte = read(fd, string, buffer);
		if (byte == 0)
		{
			free(string);
			
			break;
		}
		string[byte] = '\0';
		char *tmp = str;
		str = ft_strjoin(tmp, string);
		free(tmp);
	}
	if (!str)
		return NULL;
	comb = ft_strjoin(reste, str);
	while (comb[i] && comb[i] != '\n')
	{
		s1[0] = comb[i];
		s1[1] = '\0';
		s = ft_strjoin(s, s1);
		i++;
	}
	// for \n
	s1[0] = comb[i];
	s1[1] = '\0';
	s = ft_strjoin(s, s1);
	i++;
	if (comb[i] == '\0')
		reste = NULL;
	else
		reste = ft_strdup(&comb[i]);
	return(s);
}

// int main()
// {
// 	int fd = open("my.txt", O_RDWR);

// 	char	*line = get_next_line(fd);
// 	// printf("%s", line);
// 	// line = get_next_line(fd);
// 	// printf("%s", line);
// 	// line = get_next_line(fd);
// 	// printf("%s", line);
// 	// line = get_next_line(fd);
// 	// printf("%s", line);  
// 	while (line)
// 	{
// 		printf("%s", line);
// 		line = get_next_line(fd);
// 	}
	
// 	// char *s = NULL;
// 	// s = get_next_line(fd);
// 	// // printf("1st : %s", s);
// 	// // write(1, s, ft_strlen(s));
// 	// // printf("11");
// 	// // printf("\n");
	
// 	// char *s1 = NULL;
// 	// s1 = get_next_line(fd);
// 	// // printf("2nd : %s", s1);
// 	// // write(1, s1, ft_strlen(s1));
// 	// // printf("22");
// 	// // printf("\n");
	
// 	// char *s2 = NULL;
// 	// s2 = get_next_line(fd);
// 	// // printf("3nd : %s", s2);
// 	// // write(1, s1, ft_strlen(s1));
// 	// // printf("3");
// 	// // printf("\n");

// 	// char *s3 = NULL;
// 	// s3 = get_next_line(fd);
// 	// // printf("4nd : %s", s3);
// 	// // write(1, s1, ft_strlen(s1));
// 	// // printf("4");
// 	// // printf("\n");
		
// 	close(fd);
// }