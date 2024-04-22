#include "get_next_line.h"

t_list	*line_fetcher(int fd, t_list **lst, char *buffer)
{
	// check \n ir \0 in lst
	// fetch lines with read
	// put lines into nodes
	// append nodes to lst
	// check for \n or \0
	// if \n or \0 is found return lst

	// while (bytes_read = read(fd, buffer, BUFFER_SIZE))
	// {
	// }
}

char	*get_line(t_list **lst)
{
	// receive lst
	// count char until \n or \0 and malloc that size
	// add copy lst -> str to line until \n or \0 is found
	// return line
}

t_list	*set_next_line(t_list **old_lst)
{
	// receice old_lst
	// create new_lst 
	// add last node of previous old_lst after \n
	// clear old_lst
	// return new_lst
}

char *get_next_line(int fd)
{
	static t_list	*lst;
	char			*line_2_read;
	int				bytes_read;
	char			*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, 0))
			return (NULL);

	lst = line_fetcher(fd, lst, buffer); // checks and adds content until \n or \0

	line_2_read = get_line(lst); // creates line that is \n terminated 

	lst = set_next_line(lst); // empties lst leaving only the beginning of next line

	return (line_2_read);
}

// fetch line and add to lst
// check for \n or \0 in new node
// when \n is found make a string add all the previous nodes until \n and return it
// create a new lst starting from the char after \n and free and delete previous lst
// check for \n in new lst and redo the loop

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