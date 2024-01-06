/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:16:47 by amalbrei          #+#    #+#             */
/*   Updated: 2022/08/11 18:34:33 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_scan_buffer(int fd, char *line_read);
char	*ft_get_line(char *line_read);
char	*ft_save_extra_characters(char *line_read);
char	*ft_strjoingnl(char *left_str, char *buff);
char	*ft_strchrgnl(char *s, int c);
size_t	ft_strlengnl(char *s);

#endif