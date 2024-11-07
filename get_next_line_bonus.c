#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = 1;
	line = NULL;
	line = ft_strjoin(line, buffer);
	while (!ft_strchr(buffer, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = 0;
		if (bytes_read <= -1)
			return (free(line), NULL);
		line = ft_strjoin(line, buffer);
		if (!line)
			return (NULL);
	}
	line = clean_line(line);
	if (!line || !*line)
		return (free(line), NULL);
	clean_buffer(buffer);
	return (line);
}
