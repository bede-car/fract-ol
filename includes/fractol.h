/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:58:00 by bede-car          #+#    #+#             */
/*   Updated: 2023/01/22 11:36:11 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// # include <stdlib.h>
// # include <stdio.h>
// # include <string.h>
# include <math.h>
# include <mlx.h>
// # include <X11/X.h>
# include <X11/keysym.h>
# include "../libftprintf/source/ft_printf.h"

# define ERROR EXIT_FAILURE
# define SUCCESS EXIT_SUCCESS
# define WIDTH 600
# define HEIGHT 500

typedef struct s_math
{
	int		pixel_x;
	int		pixel_y;
	double	complex_real;
	double	complex_img;
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
	double	x_square;
	double	y_square;
	double	number_real;
	double	number_img;
	double	julia_x;
	double	julia_y;
	int		interations;
	int		max_interation;
	void	(*fractal)(struct s_math *math);

}	t_math;

typedef struct s_lib
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*add_img;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

}	t_lib;

typedef struct s_data
{
	t_lib	lib;
	t_math	math;

}	t_data;

int		creating_window(t_lib *lib);
int		creating_image(t_lib *lib);
int		destroying_window(t_lib *lib);
void	invalid_option(void);
void	parameter_not_found(void);
void	error_mandelbrot(void);
void	error_julia(void);
void	check_fractal_set(int argc, char **argv, t_math *math);
void	strtolower(char *str);
int		is_mandelbrot(int argc, char **argv);
int		is_julia(int argc, char **argv);
int		keyboard_events(int keycode, t_data *data);
int		mouse_events(int event, int x, int y, t_data *data);
void	render_fractal(t_data *data);
void	my_mlx_pixel_put(t_lib *lib, int x, int y, int color);
int		define_color(t_math *math);
void	complex_numbers(t_math *math);
void	mandelbrot(t_math *math);
void	julia(t_math *math);
void	init_math(t_math *math);

#endif
