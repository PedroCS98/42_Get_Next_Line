#include "get_next_line.h"

char	*get_line(int fd, char *str, char *buffer)
{
	// check for \n ir \0 in str
	// loop this ↓
	// 		fetch lines with read
	// 		join buffer to str
	// 		check for \n or \0 in str
	// ↑
	// if \n or \0 is found return str

	if (ft_strchr(str, '\n'))
		return (str);
	while (read(fd, buffer, BUFFER_SIZE))
	{
		ft_strjoin(str, buffer);
		if(ft_strchr(buffer, '\n'))
			return (str);
	}
	
}

char	*put_line_in_str(char *str)
{
	// receive str
	// count char until \n or \0 and malloc that size
	// copy str up to \n or \0 to line
	// return line

	
}

char	*set_next_line(char *old_str)
{
	// receice old_str
	// create new_str 
	// copy old_str after \n to new_str
	// free old_str
	// return new_str
}

char *get_next_line(int fd)
{
	static char	*str;
	char		*line_2_read;
	int			bytes_read;
	char		buffer[BUFFER_SIZE];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, 0) == -1)
		return (NULL);

	str = get_line(fd, str, buffer); // checks and adds content until \n or \0

	line_2_read = put_line_in_str(str); // creates line that is \n terminated 

	str = set_next_line(str); // empties str leaving only the beginning of next line

	return (line_2_read);
}

/*
A good start would be to know what a static variable is

get_next_line() function should let you read the text file 
pointed to by the file descriptor, one line at a time

our function should return the line that was read.
If there is nothing else to read or if an error occurred, it should return NULL.

Make sure that your function works as expected both when reading a file and when
reading from the standard input.

Please note that the returned line should include the terminating \n character,
except if the end of file was reached and does not end with a \n character.

Because you will have to read files in get_next_line(), add this option to your
compiler call: -D BUFFER_SIZE=n
It will define the buffer size for read().
The buffer size value will be modified by your peer-evaluators and the Moulinette
in order to test your code.

You will compile your code as follows (a buffer size of 42 is used as an example):
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c

We consider that get_next_line() has an undefined behavior if the file pointed to
by the file descriptor changed since the last call whereas read() didn’t reach the
end of file.

We also consider that get_next_line() has an undefined behavior when reading
a binary file. However, you can implement a logical way to handle this behavior if
you want to.

BONUS

Develop get_next_line() using only one static variable.

Your get_next_line() can manage multiple file descriptors at the same time.
For example, if you can read from the file descriptors 3, 4 and 5, you should be
able to read from a different fd per call without losing the reading thread of each
file descriptor or returning a line from another fd.

Append the _bonus.[c\h] suffix to the bonus part files.
It means that, in addition to the mandatory part files, you will turn in the 3 following
files:
• get_next_line_bonus.c
• get_next_line_bonus.h
• get_next_line_utils_bonus.c
*/