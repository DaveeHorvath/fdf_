/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 21:10:40 by dhorvath          #+#    #+#             */
/*   Updated: 2023/11/13 16:44:16 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*substring(char *original, int end);
int		has_next_line(char *s);
size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);
char	*return_if_not_read(char *buf, char **prev, int just_read);
char	*concat(char *prev, char *buf, int read);
char	*get_return(char **prev, char *buf);
char	*shrink_prev(char *prev, int endl_index);

#endif