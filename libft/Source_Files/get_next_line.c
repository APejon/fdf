/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:16:14 by amalbrei          #+#    #+#             */
/*   Updated: 2022/08/11 18:36:32 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* DESCRIPTION
Function used to malloc the buffer and join it to a variable string 
(line_read) containing the line to be read (either first line or updated from 
previous entries) and prepare it to be transferred to a return variable 
line_shown

PARAMETERS

-int fd: file descriptor of the file to be read (usually obtained from open()
function)

-char *line_read: variable to return which will be used to return what is read
*/
char	*ft_scan_buffer(int fd, char *line_read)
{
	char	*buff;
	int		no_of_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	no_of_bytes = 1;
	while (!ft_strchrgnl(line_read, '\n') && no_of_bytes != 0)
	{
		no_of_bytes = read(fd, buff, BUFFER_SIZE);
		if (no_of_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[no_of_bytes] = '\0';
		line_read = ft_strjoingnl(line_read, buff);
	}
	free(buff);
	return (line_read);
}

/* Project's PDF: https://cdn.intra.42.fr/pdf/pdf/50057/en.subject.pdf

DESCRIPTION
Function that will return a part of the file read from the target file 
(amount of characters read depends on the BUFFER_SIZE, repeated calls may 
be required to read entire file)

PARAMETERS

int fd: file descriptor of the file to be read (usually obtained from open()
function)
*/
char	*get_next_line(int fd)
{
	char			*line_shown;
	static char		*line_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483647)
		return (NULL);
	line_read = ft_scan_buffer(fd, line_read);
	if (!line_read || line_read[0] == '\0')
	{
		if (line_read)
			free(line_read);
		line_read = NULL;
		return (NULL);
	}
	line_shown = ft_get_line(line_read);
	line_read = ft_save_extra_characters(line_read);
	if (line_read[0] == '\0')
	{
		free(line_read);
		line_read = NULL;
	}
	return (line_shown);
}
