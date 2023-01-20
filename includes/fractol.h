/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:58:00 by bede-car          #+#    #+#             */
/*   Updated: 2023/01/20 15:10:50 by bede-car         ###   ########.fr       */
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

//auxiliares para retorno de função 0 -> ok diferente -> erro
# define ERROR EXIT_FAILURE
# define SUCCESS EXIT_SUCCESS
//definições da janela
# define WIDTH 600
# define HEIGHT 600
// definições de mensagem de erro
// # define MSG0 "Invalid option! You need to choose and type the name of the fractal set:"
// # define MSG1 "In case of Mandelbrot set, type only: mandelbrot"
// # define MSG2 "In case of Julia set, type the name folowed the parameters: Julia 0.4 -0.6"
// # define MSG3 "exemples: ./fractol Mandelbrot or ./Julia 0.4 0.6"

typedef struct	s_math //variáveis dos cálculos.
{
    int (*fractal)(double complex_real, double complex_img);
}t_math;

typedef struct	s_lib //variáveis da mlx
{
	void *mlx;
	void *win;
	void *img;
	char *add_img;
	int bits_per_pixel;
	int size_line;
	int endian;
}t_lib;

typedef struct	s_data //variáveis dos cálculos.
{
	t_lib lib;
    t_math math;
}t_data;


//main.c
int creating_window(t_lib *lib);
int creating_image(t_lib *lib);
int destroying_window(t_lib *lib);

//error.c
void	invalid_option(void);
void	parameter_not_found(void);
void	error_mandelbrot(void);
void	error_julia(void);

//set_fractal.c
void check_fractol_set(int argc, char ** argv, t_math *math);
void strtolower(char *str);
int	is_mandelbrot(int argc, char **argv);
int	is_julia(int argc, char **argv);

//events.c
int keyboard_events(int keycode, t_lib *mlx);
int mouse_events(int event, int x, int y, t_lib *mlx);

//fractal.c
int mandelbrot(double complex_real, double complex_img);
int julia(double complex_real, double complex_img);


#endif