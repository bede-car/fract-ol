/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 19:12:42 by bede-car          #+#    #+#             */
/*   Updated: 2023/01/03 21:54:09 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* Main function, here I am checking the arguments passed by the users        */
/* ************************************************************************** */
#include "../includes/fractol.h"

int main(int argc, char** argv)
{
	t_mlx mlx;
	if(check_fractol_set(argc, argv) == ERROR)
		return(ERROR);
	if(creating_window(&mlx) == SUCCESS)
	{
		mlx_hook(mlx.win, 2, 1L<<0, keyboard_events, &mlx);
		mlx_mouse_hook(mlx.win, mouse_events, &mlx);
		mlx_hook(mlx.win, 17, 1L<<17, destroying_window, &mlx);
		//draw window
		mlx_loop(mlx.mlx);
	}
    return(0);
}

// Validação de argumentos de entrada:
//./fractol Mandelbrot
// argc = 2
// argv argv[0][] = ./fractol
// argv argv[1][] = Mandelbrot


// abrir janela
// definição de hooks (mouse, tecla x)
// evento do hook
// print fractol (set) --> desenhar pixel a pixel
// destruir a imagem
// fecha a janela

// window
// hook