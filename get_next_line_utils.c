#include "get_next_line.h"

/*
char	*ft_strdup(const char *s)
{
	char	*dest;

	dest = (char *)malloc(ft_strlen(s) + 1);
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, s, ft_strlen(s) + 1);
	return (dest);
}
*/

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = -1;
	while (s[++i])
		;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if(!s)
		return (NULL);
	i = -1;
	while (++i <= (int)ft_strlen(s))
		if (s[i] == (char) c)
			return ((char *)(s + i));
	return (NULL);
}

/*
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	substr = (char *)ft_calloc(len + 1, 1);
	if (substr == NULL)
		return (NULL);
	if (ft_strlen(s) >= len)
		ft_strlcpy(substr, s + start, len + 1);
	else
		ft_strlcpy(substr, s + start, ft_strlen(s) + 1);
	return (substr);
}
*/

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*str;

	if (!s1)
		s1 = "";
	if (!s2)
		return (0);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcat(str, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (str);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	if ((!dst || !src) && !size)
		return (0);
	i = ft_strlen(dst);
	if (size == 0 || size <= i--)
		return (ft_strlen(src) + size);
	j = i + 1;
	while (++i < size - 1 && src[i - j])
		dst[i] = src[i - j];
	dst[i] = '\0';
	return (j + ft_strlen(src));
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = -1;
	while (++i < (size - 1) && src[i])
		dst[i] = src[i];
	dst[i] = '\0';
	return (ft_strlen(src));
}