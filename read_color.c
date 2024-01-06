/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:49:44 by amalbrei          #+#    #+#             */
/*   Updated: 2022/08/21 15:27:16 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include "fdf.h"

/* DESCRIPTION

Figures out the color of the grids.

PARAMETERS

t_data **data: structure containing the color hexadecimals and col1,col2.
char c: the flag which indicates if there is a z component to the grid or not.

NOTE

COLOR		/		CODE
0xc09966	/		Brown
0x0d8767	/		Dark Green
0xffa500	/		Orange
0xaa33cc	/		Purple
0x80d7cc	/		Dark Cyan
0xdc19a0	/		Pink
0xff0000	/		Red
0x32cd32	/		Lime Green
0x0000ff	/		Blue
0xffffff	/		White
*/
void	color(t_data **data, char c)
{
	int	col[10];

	col[0] = 0xc09966;
	col[1] = 0x0d8767;
	col[2] = 0xffa500;
	col[3] = 0xaa33cc;
	col[4] = 0x80d7cc;
	col[5] = 0xdc19a0;
	col[6] = 0xff0000;
	col[7] = 0x32cd32;
	col[8] = 0x0000ff;
	col[9] = 0xffffff;
	if ((*data)->col1 > 9)
		(*data)->col1 = 0;
	else if ((*data)->col1 < 0)
		(*data)->col1 = 9;
	if ((*data)->col2 > 9)
		(*data)->col2 = 0;
	else if ((*data)->col2 < 0)
		(*data)->col2 = 9;
	if (c == 'a')
		(*data)->color = col[(*data)->col1];
	else if (c == 'b')
		(*data)->color = col[(*data)->col2];
}

/* DESCRIPTION

Converts hexadecimals into integers, defaults to 0xffffff (or 255 indicating
 white) if empty.

PARAMETERS

char *str: the character string containing the hexadecimal number.

NOTE

Skips the 0x portion of the hexadecimal and converts each part after accordingly.
*/
int	ft_strhex_int(char *str)
{
	int	nbr;
	int	i;
	int	len;

	nbr = 0;
	i = 0;
	len = ft_strlen(str);
	while (str[i] && str[i] != 'x')
		i++;
	if (str[i] != 'x')
		return (nbr);
	i++;
	while (i < len)
	{
		if (str[i] >= '0' && str[i] <= '9')
			nbr = 16 * nbr + str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
			nbr = 16 * nbr + str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'F')
			nbr = 16 * nbr + str[i] - 'A' + 10;
		i++;
	}
	if (!nbr)
		nbr = 0xffffff;
	return (nbr);
}

/* DESCRIPTION

Fills a matrix obtained from the given .fdf file, turning all character arrays
into integers and assign them to 2D int array.

PARAMETERS

int *z_color: the matrix to be filled with hexadecimal numbers
char *line: the line to transfer unto the matrix by splitting and converting 
them into integers.

NOTE

Every call of this function will handle one line of numbers, then using while 
loop to transfer each array.
*/
void	fill_color(int	*z_color, char *line)
{
	char	**nums;
	int		i;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i])
	{
		if (!nums[i])
		{
			free(nums[i]);
			break ;
		}
		z_color[i] = ft_strhex_int(nums[i]);
		free(nums[i++]);
	}
	free(nums);
}

/* DESCRIPTION

Reads the file given within the argument and transfer it into a matrix for 
later use, planning the drawing of the 3D grid (this one is for colors
indicated with hexadecimals, which are turned into integers).

PARAMETERS

char *file_name: file to be opened and read.
t_data **data: struct containing data about the file received.

*/
void	read_color(char *file, t_data **data)
{
	int	fd;
	int	i;

	(*data)->z_color = (int **)malloc(sizeof(int *) * ((*data)->height + 1));
	if (!(*data)->z_color)
		fail_free(data, ERR_MALLOC, '3');
	i = 0;
	while (i < (*data)->height)
	{
		(*data)->z_color[i] = (int *)malloc(sizeof(int) * ((*data)->width + 1));
		if (!(*data)->z_color[i++])
			fail_free(data, ERR_MALLOC, '4');
	}
	i = 0;
	fd = open(file, O_RDONLY);
	if (!fd)
		fail_free(data, ERR_FILE, '5');
	while (i < (*data)->height)
		fill_color((*data)->z_color[i++], get_next_line(fd));
	(*data)->z_color[i] = NULL;
	close(fd);
}
