/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimoes <psimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:27:31 by psimoes           #+#    #+#             */
/*   Updated: 2024/06/09 15:04:40 by psimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*clean_stash(char *old_stash, char *line_read)
{
	char	*new_stash;
	int		i;
	int		j;
	int		size;

	size = ft_strlen(old_stash) - ft_strlen(line_read) + 1;
	new_stash = (char *)malloc(size);
	if (new_stash == NULL)
		return (NULL);
	//ft_memset(new_stash, 0, size + 1);
	i = -1;
	while (++i < size)
		((unsigned char *) new_stash)[i] = (unsigned char) 0;
	i = ft_strlen(line_read) - 1;
	j = 0;
	while (/*++i <= ft_strlen(old_stash)*/ /*&& old_stash[i] != '\n' &&*/ old_stash[++i] != '\0')
		new_stash[j++] = old_stash[i];
	new_stash[i] = '\0';
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
	//ft_memset(line_2_read, 0, size + 2);
	i = -1;
	while (++i < size + 2)
		((unsigned char *) line_2_read)[i] = (unsigned char) 0;
	i = -1;
	while (stash[++i] != '\n' && stash[i] != '\0')
		line_2_read[i] = stash[i];
	//printf("copied %d bytes from stash", i);
	if (stash[i] == '\n' || stash[i] == '\0')
		line_2_read[i] = stash[i];
	line_2_read[++i] = '\0';
	//printf("\nThe stash was: %s\nthe line returned is: %s\n", stash, line_2_read);
	//stash = clean_stash(stash, line_2_read);
	return (line_2_read);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		buffer[BUFFER_SIZE + 1];
	char		*line_2_read;
	ssize_t		bytes_read;

	//bytes_read = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!ft_strchr(stash, '\n') /*|| !ft_strchr(buffer, '\0')*/)
	{
		while (1/*bytes_read > 0*/)
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			//printf("\nThe buffer is - %s\n\n", buffer);
			stash = ft_strjoin(stash, buffer);
			//printf("\nThe stash is - %s\n\n", stash);
			if (ft_strchr(buffer, '\n') || bytes_read <= 0 /*|| ft_strchr(buffer, '\0')*/)
				break ;
		}
	}
	//printf("\nThe stash is - %s\n\n", stash);
	//printf("%zu bytes - ", bytes_read);
	if (bytes_read <= 0)
	{
		free(stash);
		return (NULL);
	}
	line_2_read = put_stash_in_line(stash);
	stash = clean_stash(stash, line_2_read);
	return (line_2_read);
}
