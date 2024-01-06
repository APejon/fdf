/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:29:20 by amalbrei          #+#    #+#             */
/*   Updated: 2022/11/14 16:04:30 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/* write */
# include <unistd.h>

/* malloc, free and exit */
# include <stdlib.h>

/* open and unlink */
# include <fcntl.h>

/* sin and cos */
# include <math.h>

/* for mlx */
# include "mlx/mlx.h"

/* for libft */
# include "libft/Includes/libft.h"

/* for ft_printf */
# include "libft/Includes/pt_printf.h"

/* for get_next_line */
# include "libft/Includes/get_next_line.h"

# define ERR_INPUT "Invalid number of arguments or invalid input\n\
Make sure its only the program and its input file, ex: \"./fdf *.fdf\""

# define ERR_MALLOC "Failed malloc"

# define ERR_FILE "File Failed to open"

# define INVALID_FILE "File does not exist or permissions denied.\n\
Check them with: ls -l"

# define ERR_EMPTY "The File is empty.\n you playin me boi? >:("

typedef struct s_addr {
	void	*i_p;
	char	*ad;
	int		pix_bi;
	int		line_by;
	int		endian;
}	t_addr;

typedef struct s_data {
	void	*mlx;
	void	*win;
	int		w_w;
	int		w_h;
	int		height;
	int		width;
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	int		col1;
	int		col2;
	int		**z_matrix;
	int		**z_color;
	double	error;
	double	error2;
	double	swap;
	double	x;
	double	y;
	double	z;
	double	x1;
	double	y1;
	double	z1;
	double	x2;
	double	y2;
	double	z2;
	double	x3;
	double	y3;
	double	x4;
	double	y4;
	double	ox;
	double	oy;
	double	sign1;
	double	sign2;
	double	x_step;
	double	y_step;
	double	my_z;
	double	temp;
	double	p;
	double	alpha;
	double	theta;
	double	gamma;
	double	r[9];
	double	temp2[4];
	t_addr	*add;
}	t_data;

/* fdf.c */
void	ft_keys_p(int key, t_data **data);
void	ft_keys_zoom(int key, t_data **data);
void	ft_keys(int key, t_data **data);
int		input_key(int key, t_data **ch);

/* error_free.c */
void	c4(t_data **data);
void	c5(t_data **data);
int		msg(char *err);
int		fail_free(t_data **data, char *err, char c);
int		check_ext(char *file_name);

/* more_free.c */
void	c3(t_data **data);
int		close_windowx(t_data **data);

/* read_file.c */
int		fdf_getwordcount(const char *s, char c);
void	get_height_width(t_data **data, char *file_name);
void	fill_matrix(t_data **data, int *z_matrix, char *line);
void	read_file(char *file_name, t_data **d);

/* read_color.c */
void	color(t_data **data, char c);
void	fill_color(int	*z_color, char *line);
void	read_color(char *file, t_data **data);

/* draw.c */
double	ft_fabs(double a);
void	bres_decision(t_data **data, int i);
void	bres_frag(t_data **data);
void	bresenham(int x, int y, t_data **data, char flagb);
void	draw(t_data **data);

/* rotate.c */
int		get_sign(int n);
void	rot_matrix(t_data **data, double *z);
void	rot_neg_matrix(t_data **data, double *z);
void	rotinit(t_data **data);
void	rotate(t_data **data, int x, int y);

/* utility.c */
void	close_window(int key, t_data **data);
void	coord_init(char *file_name, t_data **data);
void	fdf_init(t_data **d);
void	print_info(t_data **fdf);
void	my_mlx_pixel_put(t_data **data, int x, int y, int color);

#endif