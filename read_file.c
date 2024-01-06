/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:13:07 by amalbrei          #+#    #+#             */
/*   Updated: 2022/08/27 14:18:30 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_getwordcount(const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			j++;
			i++;
		}
		else if (s[i] != c && s[i + 1] != c)
			i++;
	}
	return (j);
}

/* DESCRIPTION

Calculates the height of a .fdf file's grid using get_next_line until end of file
 and reads the number of words for the width.

PARAMETERS

t_data **d: struct containing data about the file received.
char *file_name: file to be opened and read.

*/
void	get_height_width(t_data **data, char *file_name)
{
	int		fd;
	int		height;
	int		width;
	char	*line;

	height = 0;
	fd = open(file_name, O_RDONLY);
	if (!fd)
		fail_free(data, ERR_FILE, '3');
	line = get_next_line(fd);
	if (!line)
		fail_free(data, ERR_EMPTY, '1');
	width = fdf_getwordcount(line, ' ');
	height++;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		height++;
		free(line);
	}
	close(fd);
	(*data)->width = width;
	(*data)->height = height;
}

/* DESCRIPTION

Fills a matrix obtained from the given .fdf file, turning all character arrays
into integers and assign them to 2D int array.

PARAMETERS

int *z_matrix: the matrix to be filled with numbers
char *line: the line to transfer unto the matrix by splitting and atoi'ing into 
the matrix.

NOTE

Every call of this function will handle one line of numbers, then using while 
loop to transfer each array.
*/
void	fill_matrix(t_data **data, int *z_matrix, char *line)
{
	char	**nums;
	int		i;

	nums = ft_split(line, ' ');
	if (!nums)
		fail_free(data, ERR_MALLOC, '3');
	i = 0;
	while (nums[i])
	{
		z_matrix[i] = ft_atoi(nums[i]);
		free(nums[i++]);
	}
	free(nums);
}

/* DESCRIPTION

Reads the file given within the argument and transfer it into a matrix for 
later use, planning the drawing of the 3D grid.

PARAMETERS

char *file_name: file to be opened and read.
t_data **d: struct containing data about the file received.

*/
void	read_file(char *file_name, t_data **d)
{
	int		i;
	int		fd;

	(*d)->z_matrix = (int **)malloc(sizeof(int *) * ((*d)->height + 1));
	if (!(*d)->z_matrix)
		fail_free(d, ERR_MALLOC, '1');
	i = 0;
	while (i < (*d)->height)
	{
		(*d)->z_matrix[i] = (int *)malloc(sizeof(int) * ((*d)->width + 1));
		if (!(*d)->z_matrix[i++])
			fail_free(d, ERR_MALLOC, '2');
	}
	fd = open(file_name, O_RDONLY);
	if (!fd)
		fail_free(d, ERR_FILE, '3');
	i = 0;
	while (i < (*d)->height)
		fill_matrix(d, (*d)->z_matrix[i++], get_next_line(fd));
	(*d)->z_matrix[i] = NULL;
	close(fd);
}
