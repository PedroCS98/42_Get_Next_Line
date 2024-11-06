/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimoes <psimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:27:10 by psimoes           #+#    #+#             */
/*   Updated: 2024/06/08 16:09:55 by psimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*put_stash_in_line(char *stash);
char	*clean_stash(char *old_stash, char *line_read);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char const *s2);
size_t	ft_strlen(const char *s);

#endif