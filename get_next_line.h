#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

typedef struct get_next_line
{
	char					*str;
	struct get_next_line	*next;
} t_list;

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void get_next_line();

#endif