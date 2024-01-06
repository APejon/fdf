/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:42:26 by amalbrei          #+#    #+#             */
/*   Updated: 2022/11/20 16:46:49 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*DESCRIPTION

Receives keyboard presses as inputs to perform the respective changes 
to the image, this function is specified for changing perspectives.

PARAMETERS

int key: the keycode of the button pressed, see link below for codes.
(https://eastmanreference.com/complete-list-of-applescript-key-codes)

t_data **data: struct to make changes on sent as double struct pointer.

NOTES
*/
void	ft_keys_p(int key, t_data **data)
{
	if (key == 8)
	{
		(*data)->alpha = 63.4;
		(*data)->theta = 0;
		(*data)->gamma = 0;
	}
	if (key == 3)
	{
		(*data)->alpha = 0;
		(*data)->theta = 0;
		(*data)->gamma = 0;
	}
	if (key == 15)
	{
		(*data)->alpha = 90;
		(*data)->theta = 0;
		(*data)->gamma = 0;
	}
	if (key == 46)
	{
		(*data)->alpha = 35.264;
		(*data)->theta = 45;
		(*data)->gamma = 0;
	}
}

/*DESCRIPTION

Receives keyboard presses as inputs to perform the respective changes 
to the image, this function is specified for zooming.

PARAMETERS

int key: the keycode of the button pressed, see link below for codes.
(https://eastmanreference.com/complete-list-of-applescript-key-codes)

t_data **data: struct to make changes on sent as double struct pointer.

NOTES

Zooming changes varies based on map size and zoom is prevented to become negative
to avoid complicating the equations it is used in and cause 
"floating points exception".
*/
void	ft_keys_zoom(int key, t_data **data)
{
	if (key == 13 && (*data)->width < 100)
		(*data)->zoom += 1;
	if (key == 1 && (*data)->width < 100)
	{
		(*data)->zoom -= 1;
		if ((*data)->zoom < 1)
			(*data)->zoom = 1;
	}
	if (key == 13 && (*data)->width > 100)
		(*data)->zoom += 1;
	if (key == 1 && (*data)->width > 100)
	{
		(*data)->zoom -= 1;
		if ((*data)->zoom < 1)
			(*data)->zoom = 1;
	}
	ft_keys_p(key, data);
}

/*DESCRIPTION

Receives keyboard presses as inputs to perform the respective changes 
to the image (extended to avoid 25 lines in one function problem).

PARAMETERS

int key: the keycode of the button pressed, see link below for codes.
(https://eastmanreference.com/complete-list-of-applescript-key-codes)

t_data **data: struct to make changes on sent as double struct pointer.

NOTES

This form of inputs separation by functions can be helpful to organize changes.
*/
void	ft_keys(int key, t_data **data)
{
	close_window(key, data);
	if (key == 126)
		(*data)->shift_y -= 10;
	if (key == 125)
		(*data)->shift_y += 10;
	if (key == 123)
		(*data)->shift_x -= 10;
	if (key == 124)
		(*data)->shift_x += 10;
	if (key == 24)
		(*data)->my_z += 0.5;
	if (key == 27)
		(*data)->my_z -= 0.5;
	ft_keys_zoom(key, data);
}

/*DESCRIPTION

Receives keyboard presses as inputs to perform the respective changes 
to the image.

PARAMETERS

int key: the keycode of the button pressed, see link below for codes.
(https://eastmanreference.com/complete-list-of-applescript-key-codes)

t_data **ch: struct to make changes on sent as double struct pointer.

NOTES*/
int	input_key(int key, t_data **ch)
{
	ft_keys(key, ch);
	if (key == 34)
		(*ch)->alpha += 3;
	if (key == 40)
		(*ch)->alpha -= 3;
	if (key == 37)
		(*ch)->theta += 3;
	if (key == 38)
		(*ch)->theta -= 3;
	if (key == 32)
		(*ch)->gamma += 3;
	if (key == 31)
		(*ch)->gamma -= 3;
	if (key == 11)
		(*ch)->col1 += 1;
	if (key == 9)
		(*ch)->col2 += 1;
	fdf_init(ch);
	return (0);
}

/* Project's PDF: https://cdn.intra.42.fr/pdf/pdf/52122/en.subject.pdf

DESCRIPTION

Draws a 3D grid of a ".fdf" map, containing an x,y and z components to indicate
how the map should look like, utilizing minilibx, bressenham and isometric
perspective to create a window and draw an image by placing multiple pixels.

PARAMETERS

int ac: number of arguments from the command line.
char **av: the strings of arguments received from the command line.

NOTES

fflush(*standard output): sends out the outputs intended for the standard output
immediately without waiting for the window and image creation to finish.

mlx commands used:
	-mlx_init
	-mlx_new_window
	-mlx_new_image
	-mlx_get_data_addr
	-mlx_put_image_to_window
	-my_mlx_pixel_put (made by 42 docs)
	-mlx_clear_window
	-mlx_destroy_image
	-mlx_destroy_window
	-mlx_loop
*/
int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2 || check_ext(av[1]))
		return (msg(ERR_INPUT));
	if (open(av[1], O_RDONLY) == -1)
		return (msg(INVALID_FILE));
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (msg(ERR_MALLOC));
	data->add = (t_addr *)malloc(sizeof(t_addr));
	if (!data->add)
		fail_free(&data, ERR_MALLOC, '0');
	coord_init(av[1], &data);
	read_file(av[1], &data);
	read_color(av[1], &data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->w_w, data->w_h,
			"FDF Project-ion");
	fdf_init(&data);
	mlx_hook(data->win, 17, 0, close_windowx, &data);
	mlx_hook(data->win, 2, 0, input_key, &data);
	mlx_loop(data->mlx);
	return (0);
}
