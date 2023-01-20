/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:58:00 by bede-car          #+#    #+#             */
/*   Updated: 2023/01/18 23:34:37 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mlx.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include "../libftprintf/source/ft_printf.h"

# define ERROR EXIT_FAILURE
# define SUCCESS EXIT_SUCCESS
# define MSG0 "Invalid option! You need to choose and type the name of the fractal set:"
# define MSG1 "In case of Mandelbrot set, type only: mandelbrot"
# define MSG2 "In case of Julia set, type the name folowed the parameters: Julia 0.4 -0.6"
# define MSG3 "exemples: ./fractol Mandelbrot or ./Julia 0.4 0.6"

// typedef struct	s_vars //fractol
// {

// }t_vars;

// typedef struct	s_minilibx //mlx
// {
//     int (*fractol)(double complex_real, double complex_img);
// }t_minilibx;



//main.c

//error.c
int check_fractol_set(int argc, char ** argv);

// //window.c
// int creating_window(t_mlx *mlx);
// int destroying_window(t_mlx *mlx);

// //hooks.c
// int keyboard_events(int keycode, t_mlx *mlx);
// int mouse_events(int event, int x, int y, t_mlx *mlx);


#endif