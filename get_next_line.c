#include "get_next_line.h"


char	*put_stash_in_line(char *stash)
{
	// receive stash
	// count char until \n or \0 and malloc that size
	// copy stash up to \n or \0 to line
	// return line
	char	*line_2_read;
	char	*temp_stash;
	int		i;

	temp_stash = stash;
	line_2_read = (char *)malloc(ft_strlen(stash) + 1);
	if (line_2_read == NULL)
		return (NULL);
	i = -1;
	while (++i <= ft_strlen(stash) && stash[i] != '\n' && stash[i] != '\0')
		line_2_read[i] = stash[i];
	if (stash[i] == '\n' || stash[i] == '\0')
		line_2_read[i] = stash[i];
	// while(++i <= ft_strlen(stash))
	// {

	// }


	return (line_2_read);
}

char	*clean_stash(char *old_stash, char *line_read)
{
	// receice old_stash
	// create new_stash 
	// copy old_stash after \n to new_stash
	// free old_stash
	// return new_stash
	char	*new_stash;
	int		i;
	int		j;

	new_stash = (char *)malloc(ft_strlen(old_stash) - ft_strlen(line_read) + 1);
	if (new_stash == NULL)
		return (NULL);
	i = ft_strlen(line_read) - 1;
	j = 0;
	while (/*++i <= ft_strlen(old_stash)*/ /*&& old_stash[i] != '\n' &&*/ old_stash[++i] != '\0')
		new_stash[j++] = old_stash[i];
	new_stash[i] = '\0';
	free(old_stash);
	return (new_stash);
}

char *get_next_line(int fd)
{
	static char	*stash;
	char		buffer[BUFFER_SIZE + 1];
	char		*line_2_read;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, 0) == -1)
		return (NULL);
	//bytes_read = 0;
	if (!ft_strchr(stash, '\n') /*|| !ft_strchr(buffer, '\0')*/)
		while ((bytes_read = read(fd, buffer, BUFFER_SIZE)))
		{
			stash = ft_strjoin(stash, buffer);
			if(ft_strchr(buffer, '\n') /*|| ft_strchr(buffer, '\0')*/)
					break;
		}
	//printf("The stash is - %s\n\n", stash);
	//printf("%zu bytes - ", bytes_read);
	if (!bytes_read)
		return (NULL);
	line_2_read = put_stash_in_line(stash); // creates line that is \n terminated 

	stash = clean_stash(stash, line_2_read); // empties stash leaving only the beginning of next line
	return (line_2_read);
}
