/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimoes <psimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:27:22 by psimoes           #+#    #+#             */
/*   Updated: 2024/05/21 20:27:22 by psimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

	if (!s2)
		return (0);
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	str[ft_strlen(s1) + ft_strlen(s2)] = 0;
	if (str == NULL)
		return (free(s1), NULL);
	i = -1;
	if (!s1)
	{
		while (s2[++i])
			str[i] = s2[i];
		return (str);
	}
	while (s1 && s1[++i])
		str[i] = s1[i];
	j = -1;
	while (s2[++j])
		str[i++] = s2[j];
	if (s1)
		free(s1);
	return (str);
}

void	clean_buffer(char *buf)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (buf[++i] != '\n' && i < BUFFER_SIZE)
		;
	if (buf[i] == '\n')
	{
		buf[i] = 0;
		i++;
		while (i < BUFFER_SIZE)
		{
			buf[j] = buf[i];
			buf[i++] = 0;
			j++;
		}
	}
	while (j < BUFFER_SIZE)
		buf[j++] = 0;
}

char	*clean_line(char *line)
{
	char	*line_2_read;
	int		i;

	i = -1;
	while (line[++i] != '\n' && line[i])
		;
	if (line[i] == '\n')
		i++;
	line_2_read = malloc(i + 1);
	if (!line_2_read)
		return (NULL);
	i = -1;
	while (line[++i] != '\n' && line[i])
		line_2_read[i] = line[i];
	if (line[i] == '\n')
		line_2_read[i++] = '\n';
	line_2_read[i] = 0;
	free(line);
	return (line_2_read);
}
