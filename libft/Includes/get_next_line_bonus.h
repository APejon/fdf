/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 19:12:33 by amalbrei          #+#    #+#             */
/*   Updated: 2022/08/11 15:14:39 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 111
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_scan_buffer(int fd, char *line_read);
char	*ft_get_line(char *line_read);
char	*ft_save_extra_characters(char *line_read);
char	*ft_strjoingnl(char *left_str, char *buff);
char	*ft_strchrgnl(char *s, int c);
size_t	ft_strlengnl(char *s);

#endif