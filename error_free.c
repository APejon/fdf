/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:49:40 by amalbrei          #+#    #+#             */
/*   Updated: 2022/08/27 11:20:33 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	c4(t_data **data)
{
	int	i;

	i = 0;
	free ((*data)->z_color);
	while (i < (*data)->height)
		free ((*data)->z_matrix[i++]);
	free ((*data)->z_matrix);
	free ((*data)->add);
	free ((*data));
}

void	c5(t_data **data)
{
	int	i;

	i = 0;
	while (i < (*data)->height)
		free ((*data)->z_color[i++]);
	free ((*data)->z_color);
	i = 0;
	while (i < (*data)->height)
		free ((*data)->z_matrix[i++]);
	free ((*data)->z_matrix);
	free ((*data)->add);
	free ((*data));
}

/* DESCRIPTION

Prints out an error message and returns an error code.

PARAMETERS

char *err: the error message.

*/
int	msg(char *err)
{
	write(1, err, ft_strlen(err));
	return (1);
}

/* DESCRIPTION

Prints out an error message and returns an error code while
freeing respective malloced pointers.

PARAMETERS

t_data **data: data to be free'd.
char *err: the error message.
char c: a flag indicating how much will be needed to be freed.

*/
int	fail_free(t_data **data, char *err, char c)
{
	write(1, err, ft_strlen(err));
	if (c == 0)
		free ((*data));
	if (c == 1)
	{
		free ((*data)->add);
		free ((*data));
	}
	if (c == 2)
	{
		free ((*data)->z_matrix);
		free ((*data)->add);
		free ((*data));
	}
	if (c == 3)
		c3(data);
	if (c == 4)
		c4(data);
	if (c == 5)
		c5(data);
	exit (1);
}

/* DESCRIPTION

Checks the extension of the file provided.

PARAMETERS

char *file_name: the file provided in the argument.
*/
int	check_ext(char *file_name)
{
	int	i;

	i = ft_strlen(file_name);
	i--;
	if (file_name[i] == 'f')
	{
		i--;
		if (file_name[i] == 'd')
		{
			i--;
			if (file_name[i] == 'f')
			{
				i--;
				if (file_name[i] == '.')
					return (0);
			}
		}
	}
	return (1);
}
