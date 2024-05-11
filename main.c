#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = -1;
// 	while (s[++i])
// 		;
// 	return (i);
// }

// char	*ft_strchr(const char *s, int c)
// {
// 	int	i;

// 	if(!s)
// 		return (NULL);
// 	i = -1;
// 	while (++i <= (int)ft_strlen(s))
// 		if (s[i] == (char) c)
// 			return ((char *)(s + i));
// 	return (NULL);
// }

int	main()
{
	//static char buffer[BUFFER_SIZE];
	int fd  = open("test.txt", O_RDONLY);
	printf("here\n");
	printf("%s\n", get_next_line(fd));
	//printf("%s\n", get_next_line(fd));
	//printf("%s\n", get_next_line(fd));

	// int x = 1;
	// while (x)
	// {
	// 	x = read(fd, buffer, BUFFER_SIZE);
	// 	if (!x)
	// 		return (0);
	// 	printf("\"%s\"\n", buffer);
	// 	if (ft_strchr(buffer, '\n'))
	// 	{
	// 		printf("found newline\n");
	// 		//return (0);
	// 	}
	// }
	close(fd);
	return (0);
}