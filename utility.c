/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:08:29 by amalbrei          #+#    #+#             */
/*   Updated: 2022/11/20 16:45:22 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*DESCRIPTION

Receives keyboard presses as inputs to close and free the whole project

PARAMETERS

int key: the keycode of the button pressed, see link below for codes.
(https://eastmanreference.com/complete-list-of-applescript-key-codes)

t_data **data: struct to make changes on sent as double struct pointer.

NOTES

This form of inputs separation by functions can be helpful to organize changes.
*/
void	close_window(int key, t_data **data)
{
	int	i;

	i = 0;
	if (key == 53)
	{
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
}

/* DESCRIPTION

Initializes all needed parameters for fdf (default angles are for isometric).

PARAMETERS

char *file_name: the map to be sent for reading (get height and width).
t_data **data: struct containing the variables to be initialized.

*/
void	coord_init(char *file_name, t_data **data)
{
	get_height_width(data, file_name);
	(*data)->w_w = 1400;
	(*data)->w_h = 1400;
	(*data)->shift_x = 10;
	(*data)->shift_y = 10;
	(*data)->my_z = 2;
	(*data)->alpha = 35.264;
	(*data)->theta = 45;
	(*data)->gamma = 0;
	(*data)->col1 = 9;
	(*data)->col2 = 6;
	if ((*data)->width >= 400)
		(*data)->zoom = 1;
	else if ((*data)->width >= 300)
		(*data)->zoom = 5;
	else if ((*data)->width >= 100)
		(*data)->zoom = 10;
	else if ((*data)->width >= 50)
		(*data)->zoom = 20;
	else
		(*data)->zoom = 30;
}

/* DESCRIPTION

Initializes all needed parameters for fdf (in terms of mlx commands).

PARAMETERS

t_data **d: struct containing the variables to be initialized.

*/
void	fdf_init(t_data **d)
{
	(*d)->add->i_p = mlx_new_image((*d)->mlx, (*d)->w_w, (*d)->w_h);
	(*d)->add->ad = mlx_get_data_addr((*d)->add->i_p, &((*d)->add->pix_bi),
			&((*d)->add->line_by), &((*d)->add->endian));
	draw(d);
	mlx_put_image_to_window((*d)->mlx, (*d)->win, (*d)->add->i_p, 0, 0);
	mlx_destroy_image((*d)->mlx, (*d)->add->i_p);
	print_info(d);
}

/* DESCRIPTION

Prints out sentences to guide users when using fdf.

PARAMETERS

t_data **fdf: struct containing the variables to be referred to.

*/
void	print_info(t_data **fdf)
{
	mlx_string_put((*fdf)->mlx, (*fdf)->win, (*fdf)->w_w - 90, 20, \
				0xffffff, "By Amalbrei");
	mlx_string_put((*fdf)->mlx, (*fdf)->win, 0, 20, 0xffffff,
		"Translate MAP : UP / DOWN / LEFT / RIGHT");
	mlx_string_put((*fdf)->mlx, (*fdf)->win, 0, 40, 0xffffff,
		"Rotation (ALPHA)X/ (THETA)Y/ (GAMMA)Z AXES: I or K / J or L/ U or O");
	mlx_string_put((*fdf)->mlx, (*fdf)->win, 0, 60, 0xffffff,
		"ZOOM IN/OUT : W/S");
	mlx_string_put((*fdf)->mlx, (*fdf)->win, 0, 80, 0xffffff,
		"ALTITUDE VARIATION PLUS/MINUS : +/-");
	mlx_string_put((*fdf)->mlx, (*fdf)->win, 0, 100, 0xffffff,
		"CHANGE COLOR FOR (Z = 0)/(Z > 0) : B/V");
	mlx_string_put((*fdf)->mlx, (*fdf)->win, 0, 120, 0xffffff,
		"ISOMETRIC: M, TOPDOWN-VIEW: F, FRONT-VIEW: R, CABINET: C");
}

/* DESCRIPTION

Function obtained from "42 Docs" which helps in placing pixels unto an image.

PARAMETERS

t_data **data: struct containing the variables to be transfered to functions.
int x: the x-coordinate on the image.
int y: the y-coordinate on the image.
int color: the color of the pixel to be placed.

NOTE

Make sure the pixels are not allowed to be placed beyond the borders of the image
using an if condition.
*/
void	my_mlx_pixel_put(t_data **data, int x, int y, int color)
{
	char	*dst;

	if ((x >= 0 && y >= 0) && (x < (*data)->w_w && y < (*data)->w_h))
	{
		dst = (*data)->add->ad + (y * (*data)->add->line_by + x
				* ((*data)->add->pix_bi / 8));
		*(unsigned int *)dst = color;
	}
}
