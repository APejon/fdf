/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 17:43:40 by amalbrei          #+#    #+#             */
/*   Updated: 2022/08/21 14:11:38 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_sign(int n)
{
	if (n < 0)
		return (-1);
	return (1);
}

void	rot_matrix(t_data **data, double *z)
{
	(*data)->temp2[0] = (z[0] * (*data)->my_z) * (*data)->r[6];
	(*data)->temp2[1] = (z[0] * (*data)->my_z) * (*data)->r[7];
	(*data)->temp2[2] = (z[1] * (*data)->my_z) * (*data)->r[6];
	(*data)->temp2[3] = (z[1] * (*data)->my_z) * (*data)->r[7];
	(*data)->temp2[0] += (*data)->ox + (*data)->shift_x + ((*data)->w_w / 2);
	(*data)->temp2[1] += (*data)->oy + (*data)->shift_y + ((*data)->w_h / 2);
	(*data)->temp2[2] += (*data)->ox + (*data)->shift_x + ((*data)->w_w / 2);
	(*data)->temp2[3] += (*data)->oy + (*data)->shift_y + ((*data)->w_h / 2);
	(*data)->temp2[0] -= ((*data)->width * (*data)->zoom / 2);
	(*data)->temp2[1] -= ((*data)->height * (*data)->zoom / 2);
	(*data)->temp2[2] -= ((*data)->width * (*data)->zoom / 2);
	(*data)->temp2[3] -= ((*data)->height * (*data)->zoom / 2);
	(*data)->x1 = (*data)->x3 * (*data)->r[0] + (*data)->y3 * (*data)->r[3]
		+ (*data)->temp2[0];
	(*data)->y1 = (*data)->x3 * (*data)->r[1] + (*data)->y3 * (*data)->r[4]
		+ (*data)->temp2[1];
	(*data)->x2 = (*data)->x4 * (*data)->r[0] + (*data)->y4 * (*data)->r[3]
		+ (*data)->temp2[2];
	(*data)->y2 = (*data)->x4 * (*data)->r[1] + (*data)->y4 * (*data)->r[4]
		+ (*data)->temp2[3];
}

void	rotinit(t_data **data)
{
	double	a;
	double	t;
	double	g;

	a = (*data)->alpha * M_PI / 180;
	t = (*data)->theta * M_PI / 180;
	g = (*data)->gamma * M_PI / 180;
	(*data)->x3 = (*data)->x1 - (*data)->ox;
	(*data)->y3 = (*data)->y1 - (*data)->oy;
	(*data)->x4 = (*data)->x2 - (*data)->ox;
	(*data)->y4 = (*data)->y2 - (*data)->oy;
	(*data)->r[0] = cos(t) * cos(g);
	(*data)->r[1] = cos(t) * sin(g);
	(*data)->r[2] = -sin(t);
	(*data)->r[3] = sin(a) * sin(t) * cos(g) - cos(a) * sin(g);
	(*data)->r[4] = sin(a) * sin(t) * sin(g) + cos(a) * cos(g);
	(*data)->r[5] = sin(a) * cos(t);
	(*data)->r[6] = cos(a) * sin(t) * cos(g) + sin(a) * sin(g);
	(*data)->r[7] = cos(a) * sin(t) * sin(g) - sin(a) * cos(g);
	(*data)->r[8] = cos(a) * cos(t);
}

void	rotate(t_data **data, int x, int y)
{
	int		va[4];
	double	z[2];

	va[0] = (int)(*data)->y1;
	va[1] = (int)(*data)->x1;
	va[2] = (int)(*data)->y2;
	va[3] = (int)(*data)->x2;
	if (va[0] / (*data)->zoom >= (*data)->height)
		va[0] = (y - 1) * (*data)->zoom;
	if (va[1] / (*data)->zoom >= (*data)->width)
		va[1] = (x - 1) * (*data)->zoom;
	if (va[2] / (*data)->zoom >= (*data)->height)
		va[2] = va[0];
	if (va[3] / (*data)->zoom >= (*data)->width)
		va[3] = va[1];
	z[0] = ((*data)->z_matrix)[va[0] / (*data)->zoom][va[1] / (*data)->zoom];
	z[1] = ((*data)->z_matrix)[va[2] / (*data)->zoom][va[3] / (*data)->zoom];
	(*data)->color
		= ((*data)->z_color)[va[0] / (*data)->zoom][va[1] / (*data)->zoom];
	if (!(z[0] || z[1]))
		color(data, 'a');
	if ((z[0] || z[1]) && (*data)->color == 0)
		color(data, 'b');
	rotinit(data);
	rot_matrix(data, z);
}
