/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:58:11 by bede-car          #+#    #+#             */
/*   Updated: 2023/01/21 12:49:02 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int main(int argc, char** argv)
{
	t_data	data;
	check_fractal_set(argc, argv, &data.math);
	if(creating_window(&data.lib) == SUCCESS && creating_image(&data.lib) == SUCCESS)
	{
		init_math(&data.math);
		mlx_key_hook(data.lib.win, keyboard_events, &data);
		mlx_mouse_hook(data.lib.win, mouse_events, &data);
		mlx_hook(data.lib.win, 17, 1L<<17, destroying_window, &data);
		render_fractal(&data);
		//mlx_put_image_to_window(data.lib.mlx, data.lib.win, data.lib.img, 0, 0);
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
	&lib->line_length, &lib->endian);	
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