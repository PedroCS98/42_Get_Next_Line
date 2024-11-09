/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimoes <psimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:27:39 by psimoes           #+#    #+#             */
/*   Updated: 2024/05/25 20:15:03 by psimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line.h"
// #include <fcntl.h>
// #include <stdio.h>

// int	main()
// {
// 	char	*line;
// 	int 	i;

// 	int fd  = open("test.txt", O_RDONLY);
// 	//int fd = 0; //std input
// 	i = 0;
// 	while ((line = get_next_line(fd)) && ++i)
// 	{
// 		printf(/*line %d - */"%s", /*i,*/ line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
    int fd1;
    int fd2;
    int fd3;
    char *ptr;

    ptr = NULL;
    if (argc != 4)
    {
        printf("\nToo many args. Usage: ./main [file] [nbr of lines]\n");
        return (1);
    }
    fd1 = open(argv[1], O_RDONLY);
    fd2 = open(argv[2], O_RDONLY);
    fd3 = open(argv[3], O_RDONLY);
    if (fd1 < 0 || fd2 < 0 || fd3 < 0)
    {
        printf("Error opening file");
        return (1);
    }
    printf("\n--- GET NEXT LINE ---\n");
    for (int i = 0; i < 10; i++)
    {

        ptr = get_next_line(fd1);
        printf("1st: %s", ptr);
        free (ptr);
        ptr = get_next_line(fd2);
        printf("%s", ptr);
        free(ptr);
        ptr = get_next_line(fd3);
        printf("%s", ptr);
        free (ptr);
    }
    printf("\n--------------------------\n");
    return (0);
}


// int	main()
// {
// 	char *line;
// 	do
// 	{
// 		line = get_next_line(0);
// 		printf("%s", line);
// 		free(line);
// 	} while (line);
	
// 	return (0);
// }
/*

Nao posso ter a verificacao inicial do get net line com o buffersize a 0

Usar Valgrind para encontrar o porque de malloc trippar qd chamo com buffersize under >= 4

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
end of file.---------------

We also consider that get_next_line() has an undefined behavior when reading
a binary file. However, you can implement a logical way to handle this behavior if
you want to.------------

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

/*
slightly improved function so it always allocs the right size
char	*put_stash_in_line(char *stash)
{
	char	*line_2_read;
	int		i;

	i = 0;
	while (stash[i+1] != '\n' && stash[i] != '\0')
		i++;
	line_2_read = (char *)malloc((i + 1) * sizeof(char));
	if (line_2_read == NULL)
		return (NULL);
	i = -1;
	while (stash[++i] != '\n' && stash[i] != '\0')
		line_2_read[i] = stash[i];
	//printf("copied %d bytes from stash", i);
	if (stash[i] == '\n')
		line_2_read[i] = stash[i++];
	line_2_read[i] = '\0';
	//printf("\nThe stash was: %s\nthe line returned is: %s\n", stash, line_2_read);
	//stash = clean_stash(stash, line_2_read);
	return (line_2_read);
}
*/