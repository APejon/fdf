/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:35:44 by amalbrei          #+#    #+#             */
/*   Updated: 2022/08/22 19:18:13 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	c3(t_data **data)
{
	int	i;

	i = 0;
	while (i < (*data)->height)
		free ((*data)->z_matrix[i++]);
	free ((*data)->z_matrix);
	free ((*data)->add);
	free ((*data));
}

int	close_windowx(t_data **data)
{
	int	i;

	i = 0;
	while (i < (*data)->height)
		free((*data)->z_matrix[i++]);
	free((*data)->z_matrix);
	i = 0;
	while (i < (*data)->height)
		free((*data)->z_color[i++]);
	free((*data)->z_color);
	mlx_clear_window((*data)->mlx, (*data)->win);
	mlx_destroy_image((*data)->mlx, (*data)->add->i_p);
	free((*data)->add);
	free((*data));
	exit(0);
}
