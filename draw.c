/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 13:19:09 by amalbrei          #+#    #+#             */
/*   Updated: 2023/06/01 15:29:51 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	 ft_fabs(double a)
{
	if (a < 0)
		return (-a);
	return (a);
}

void	bres_decision(t_data **data, int i)
{
	while (i < (*data)->x_step)
	{
		my_mlx_pixel_put(data, (*data)->x, (*data)->y, (*data)->color);
		if ((*data)->p > 0)
		{
			(*data)->p = (*data)->p + (2 * ((*data)->y_step - (*data)->x_step));
			if ((*data)->swap)
				(*data)->x += (*data)->sign1;
			else
				(*data)->y += (*data)->sign2;
		}
		else
			(*data)->p = (*data)->p + 2 * (*data)->y_step;
		if ((*data)->swap)
			(*data)->y += (*data)->sign2;
		else
			(*data)->x += (*data)->sign1;
		i++;
	}
}

void	bres_frag(t_data **data)
{
	int	i;

	(*data)->x_step = ft_fabs((*data)->x2 - (*data)->x1);
	(*data)->y_step = ft_fabs((*data)->y2 - (*data)->y1);
	(*data)->sign1 = get_sign((*data)->x2 - (*data)->x1);
	(*data)->sign2 = get_sign((*data)->y2 - (*data)->y1);
	(*data)->swap = 0;
	(*data)->x = (*data)->x1;
	(*data)->y = (*data)->y1;
	if ((*data)->y_step >= (*data)->x_step)
	{
		(*data)->temp = (*data)->x_step;
		(*data)->x_step = (*data)->y_step;
		(*data)->y_step = (*data)->temp;
		(*data)->swap = 1;
	}
	(*data)->p = (2 * (*data)->y_step) - (*data)->x_step;
	i = 0;
	bres_decision(data, i);
}

void	bresenham(int x, int y, t_data **data, char flagb)
{
	if (flagb == 'a')
	{
		(*data)->x1 = x * (*data)->zoom;
		(*data)->y1 = y * (*data)->zoom;
		(*data)->x2 = (x + 1) * (*data)->zoom;
		(*data)->y2 = y * (*data)->zoom;
	}
	else if (flagb == 'b')
	{
		(*data)->x1 = x * (*data)->zoom;
		(*data)->y1 = y * (*data)->zoom;
		(*data)->x2 = x * (*data)->zoom;
		(*data)->y2 = (y + 1) * (*data)->zoom;
	}
	(*data)->ox = (*data)->width * (*data)->zoom / 2;
	(*data)->oy = (*data)->height * (*data)->zoom / 2;
	rotate(data, x, y);
	bres_frag(data);
}

void	draw(t_data **data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y <= (*data)->height)
	{
		x = 0;
		while (x <= (*data)->width)
		{
			if (x < (*data)->width)
				bresenham(x, y, data, 'a');
			if (y < (*data)->height)
				bresenham(x, y, data, 'b');
			x++;
		}
		y++;
	}
}
