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

	if (!s1)
		s1 = NULL;
	if (!s2)
		return (0);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	//ft_memset(str, 0, ft_strlen(s1) + ft_strlen(s2) + 1);
	i = -1;
	while (++i < ft_strlen(s1) + ft_strlen(s2) + 1)
		((unsigned char *) str)[i] = (unsigned char) 0;
	i = -1;
	while (++i < ft_strlen(s1) && s1[i])
		str[i] = s1[i];
	i--;
	j = i + 1;
	while (++i < ft_strlen(s1) + ft_strlen(s2) && s2[i - j])
		str[i] = s2[i - j];
	str[i] = '\0';
	free(s1);
	return (str);
}

// void	*ft_memset(void *s, int c, size_t n)
// {
// 	size_t	i;

// 	i = -1;
// 	while (++i < n)
// 		((unsigned char *) s)[i] = (unsigned char) c;
// 	return (s);
// }

// size_t	ft_strlcat(char *dst, const char *src, size_t size)
// {
// 	size_t	i;
// 	size_t	j;

// 	if ((!dst || !src) && !size)
// 		return (0);
// 	i = ft_strlen(dst);
// 	if (size == 0 || size <= i--)
// 		return (ft_strlen(src) + size);
// 	j = i + 1;
// 	while (++i < size - 1 && src[i - j])
// 		dst[i] = src[i - j];
// 	dst[i] = '\0';
// 	return (j + ft_strlen(src));
// }

// size_t	ft_strlcpy(char *dst, const char *src, size_t size)
// {
// 	size_t	i;

// 	if (size == 0)
// 		return (ft_strlen(src));
// 	i = -1;
// 	while (++i < (size - 1) && src[i])
// 		dst[i] = src[i];
// 	dst[i] = '\0';
// 	return (ft_strlen(src));
// }
