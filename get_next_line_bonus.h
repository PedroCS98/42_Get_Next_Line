#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*clean_line(char *line);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char const *s2);
void	clean_buffer(char *buf);
size_t	ft_strlen(const char *s);

#endif
