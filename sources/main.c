/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:58:11 by bede-car          #+#    #+#             */
/*   Updated: 2023/01/20 00:27:07 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int main(int argc, char** argv)
{
	t_lib	lib;
	if(check_fractol_set(argc, argv) == ERROR)
		return(ERROR);
	// lib.title=argv[1];
	if(creating_window(&lib) == SUCCESS && creating_image(&lib) == SUCCESS)
	{
		//eventos
		//desenhar pixel
		mlx_loop(lib.mlx);
	}
	return(ERROR);
}

int creating_window(t_lib *lib)
{
	lib->mlx = mlx_init();
	if(lib->mlx == NULL)
		return(ERROR);
	lib->win = mlx_new_window(lib->mlx, WIDTH, HEIGHT, "Fract’ol");
	// lib->win=mlx_new_window(lib->mlx, WIDTH, HEIGHT, lib->title);
	if(lib->win == NULL)
	{
		free(lib->mlx);
		return(ERROR);
	}
	return(SUCCESS);
}

int creating_image(t_lib *lib)
{
	lib->img = mlx_new_image(lib->mlx, WIDTH, HEIGHT);
		if(lib->img == NULL)
		{
			free(lib->mlx);
			return(ERROR);
		}
	lib->add_img = mlx_get_data_addr(lib->img, &lib->bits_per_pixel, \
	&lib->size_line, &lib->endian);	
	return(SUCCESS);
}

//validar parametros de entrada ok
//criar janela ok 
//criar imagem ok 
//events mouse
//events teclado
//desenhar na tela
//loop


// ARGC ARGV 
// 