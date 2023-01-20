/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:58:11 by bede-car          #+#    #+#             */
/*   Updated: 2023/01/20 14:50:58 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int main(int argc, char** argv)
{
	t_data	data;
	check_fractol_set(argc, argv, &data.math);
	if(creating_window(&data.lib) == SUCCESS && creating_image(&data.lib) == SUCCESS)
	{
		//eventos
		//desenhar pixel
		mlx_loop(data.lib.mlx);
	}
	return(ERROR);
}

int creating_window(t_lib *lib)
{
	lib->mlx = mlx_init();
	if(lib->mlx == NULL)
		return(ERROR);
	lib->win = mlx_new_window(lib->mlx, WIDTH, HEIGHT, "Fract’ol");
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

int destroying_window(t_lib *lib)
{
	mlx_destroy_image(lib->mlx, lib->img);
	mlx_destroy_window(lib->mlx, lib->win);
	mlx_destroy_display(lib->mlx);
	free(lib->mlx);
	exit(SUCCESS);
}