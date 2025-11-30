/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhamdaou <yhamdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 11:45:22 by yhamdaou          #+#    #+#             */
/*   Updated: 2025/11/30 14:50:14 by yhamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next.h"

// char *get_next_line(int fd)
// {
// 	int i = 0;
// 	int buffer = 30;
// 	char s2[buffer];
// 	char s1[2];
// 	char *s = NULL;
// 	int j = 0;
// 	static char *reste = NULL;
	
// 	read(fd, s2, buffer);
// 	s2[buffer] = '\0';
// 	while (s2[i] != '\n')
// 	{
// 		s1[0] = s2[i];
// 		s1[1] = '\0';
// 		// read(fd, s2, buffer);
// 		// s2[buffer] = '\0';
// 		s = ft_strjoin(s, s1);
// 		i++;
// 	}
// 	reste = ft_strdup(&s2[i]);
// 	return(s);
// }
#include <stdio.h>

char *get_next_line(int fd)
{
	int i = 0;
	int buffer = 77;
	char s1[2];
	char *s = NULL;
	int j = 0;
	static char *reste = NULL;
	char *comb = NULL;
	int byte = 0;
	
	char *string = NULL;
	string[0] = '\0';
	char *str = NULL;
	int k = 0;
	if (ft_strchr(reste, '\n') == 1)
	{
		// printf("yes");
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
	
	// while (ft_strchr(str, '\n') != 1)
	// {
		
	// 	read(fd, string, buffer - 1);
	// 	string[buffer - 1] = '\0';
	// 	str = ft_strjoin(str, string);
	// }
		while (ft_strchr(str, '\n') != 1)
	{
		string = malloc(buffer + 1);
		byte = read(fd, string, buffer);
		string[byte] = '\0';
		str = ft_strjoin(str, string);
	}
	comb = ft_strjoin(reste, str);
	while (comb[i] != '\n')
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
	reste = ft_strdup(&comb[i]);
	return(s);
}

int main()
{
	int fd = open("my.txt", O_RDWR);
	char *s = NULL;
	s = get_next_line(fd);
	printf("1st : %s", s);
	// write(1, s, ft_strlen(s));
	printf("11");
	printf("\n");
	
	char *s1 = NULL;
	s1 = get_next_line(fd);
	printf("2nd : %s", s1);
	// write(1, s1, ft_strlen(s1));
	printf("22");
	printf("\n");
	
	char *s2 = NULL;
	s2 = get_next_line(fd);
	printf("3nd : %s", s2);
	// write(1, s1, ft_strlen(s1));
	printf("3");
	printf("\n");

	char *s3 = NULL;
	s3 = get_next_line(fd);
	printf("4nd : %s", s3);
	// write(1, s1, ft_strlen(s1));
	printf("4");
	printf("\n");
		
	close(fd);
}