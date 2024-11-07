#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = -1;
	while (++i <= (int)ft_strlen(s))
		if (s[i] == (char) c)
			return ((char *)(s + i));
	return (NULL);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1)
		s1 = NULL;
	if (!s2)
		return (0);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	i = -1;
	while (++i < ft_strlen(s1) + ft_strlen(s2) + 1)
		((unsigned char *) str)[i] = (unsigned char) 0;
	i = -1;
	while (++i < ft_strlen(s1) && s1[i])
		str[i] = s1[i];
	j = 0;
	while (j < ft_strlen(s2) && s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*clean_stash(char *old_stash, char *line_read)
{
	char	*new_stash;
	int		i;
	int		offset;
	int		new_size;

	offset = ft_strlen(line_read);
	new_size = ft_strlen(old_stash) - offset;
	new_stash = (char *)malloc(new_size + 1);
	if (new_stash == NULL)
		return (NULL);
	i = -1;
	while (++i < new_size + 1)
		((unsigned char *) new_stash)[i] = (unsigned char) 0;
	i = -1;
	while (++i < new_size)
		new_stash[i] = old_stash[i + offset];
	new_stash[new_size] = '\0';
	free(old_stash);
	return (new_stash);
}

char	*put_stash_in_line(char *stash)
{
	char	*line_2_read;
	int		i;
	int		size;

	size = 0;
	while (stash[size] != '\n' && stash[size] != '\0')
		size++;
	line_2_read = (char *)malloc((size + 2) * sizeof(char));
	if (line_2_read == NULL)
		return (NULL);
	i = -1;
	while (++i < size + 2)
		((unsigned char *) line_2_read)[i] = (unsigned char) 0;
	i = -1;
	while (stash[++i] != '\n' && stash[i] != '\0')
		line_2_read[i] = stash[i];
	if (stash[i] == '\n')
		line_2_read[i++] = '\n';
	line_2_read[i] = '\0';
	return (line_2_read);
}
