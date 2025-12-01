#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;

	i = 0;
	srclen = ft_strlen(src);
	if (src && dstsize == 0)
		return (dstsize + srclen);
	dstlen = ft_strlen(dst);
	if (dstsize <= dstlen)
		return (srclen + dstsize);
	else
	{
		while (src[i] && i < dstsize - dstlen - 1)
		{
			dst[dstlen + i] = src[i];
			i++;
		}
		dst[dstlen + i] = '\0';
		return (srclen + dstlen);
	}
}
char	*ft_strdup(const char *s1)
{
	int		i;
	int		srclen;
	char	*dst;

	srclen = ft_strlen(s1);
	i = 0;
	dst = malloc ((srclen + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	while (i < srclen)
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1len;
	int		s2len;
	char	*str;
	int		i;

	i = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if(!s1)
		return (ft_strdup(s2));
	if(!s2)
		return (ft_strdup(s1));
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	str = malloc((s1len + s2len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	ft_strlcat(str, s2, (s1len + s2len + 1));
	return (str);
}

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}
