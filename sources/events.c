/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 23:51:24 by bede-car          #+#    #+#             */
/*   Updated: 2023/01/21 11:17:20 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int keyboard_events(int keycode, t_data *data)
{
	if(keycode == XK_Escape)
		destroying_window(data->lib.mlx);
	side_move(keycode, data);
	return(SUCCESS);
}

void	side_move(int keycode, t_data *data)
{
	if (keycode != KEY_RIGHT && keycode != KEY_DOWN
		&& keycode != KEY_UP && keycode != KEY_LEFT)
		return ;
	if (keycode == KEY_RIGHT)
	{
		data->math.x_min *= 0.885;
		data->math.x_max *= 1.115;
	}
	else if (keycode == KEY_LEFT)
	{
		data->math.x_min *= 1.115;
		data->math.x_max *= 0.885;
	}
	else if (keycode == KEY_UP)
	{
		data->math.y_min *= 1.115;
		data->math.y_max *= 0.885;
	}
	else if (keycode == KEY_DOWN)
	{
		data->math.y_min *= 0.885;
		data->math.y_max *= 1.115;
	}
	render_fractal(data);
	//renderizar again
}

int mouse_events(int event, int x, int y, t_lib *mlx)
{
	(void)mlx;
	if(event == 1)
	{
		printf("coordenada da janela %d %d\n", x, y);
		printf("apertei o lado esquerdo do mouse\n");
	}
	return(SUCCESS);
}

