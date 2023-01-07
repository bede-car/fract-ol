/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:23:05 by bede-car          #+#    #+#             */
/*   Updated: 2023/01/03 22:10:43 by bede-car         ###   ########.fr       */
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
#include "../libft/libft.h"

# define ERROR EXIT_FAILURE
# define SUCCESS EXIT_SUCCESS
# define MSG "opção inválida\n"

typedef struct	s_vars //fractol
{

}t_vars;

typedef struct	s_mlx //mlx
{
    void *mlx;
    void *win;
    void *img;
    char *add_img;
    int bit_per_pixel;
    int size_line;
    int endian;
    int x;
    int y;
    int (*fractol)(double complex_real, double complex_img);
}t_mlx;

//main.c

//error.c
int check_fractol_set(int argc, char **argv);

//window.c
int creating_window(t_mlx *mlx);
int destroying_window(t_mlx *mlx);

//hooks.c
int keyboard_events(int keycode, t_mlx *mlx);
int mouse_events(int event, int x, int y, t_mlx *mlx);


#endif