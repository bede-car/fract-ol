/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:57:28 by bede-car          #+#    #+#             */
/*   Updated: 2023/01/22 00:22:47 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

void	move_key_arrow(int keycode, t_data *data)
{
	data->math.x_med = (data->math.x_max - data->math.x_min);
	data->math.y_med = (data->math.y_max - data->math.y_min);
	if (keycode == XK_Left)
	{
		data->math.x_min += data->math.x_med * 0.115;
		data->math.x_max += data->math.x_med * 0.115;
	}
	else if (keycode == XK_Right)
	{
		data->math.x_min -= data->math.x_med * 0.115;
		data->math.x_max -= data->math.x_med * 0.115;
	}
	else if (keycode == XK_Down)
	{
		data->math.y_min -= data->math.y_med * 0.115;
		data->math.y_max -= data->math.y_med * 0.115;
	}
	else if (keycode == XK_Up)
	{
		data->math.y_min += data->math.y_med * 0.115;
		data->math.y_max += data->math.y_med * 0.115;
	}
	render_fractal(data);
}

int	keyboard_events(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		destroying_window(&data->lib);
	move_key_arrow(keycode, data);
	if (keycode == 99)
	{
		data->math.color++;
		if(data->math.color == 4)
			data->math.color = 1;
		render_fractal(data);
	}
	return (SUCCESS);
}

int	mouse_events(int event, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	data->math.x_med = (data->math.x_max - data->math.x_min);
	data->math.y_med = (data->math.y_max - data->math.y_min);
	if (event != 4 && event != 5)
		return (ERROR);
	if (event == 5)
	{
		data->math.x_max += data->math.x_med * 0.115;
		data->math.x_min -= data->math.x_med * 0.115;
		data->math.y_min -= data->math.y_med * 0.115;
		data->math.y_max = data->math.y_min + \
		(data->math.x_max - data->math.x_min) * HEIGHT / WIDTH;
	}
	else if (event == 4)
	{
		data->math.x_max -= data->math.x_med * 0.115;
		data->math.x_min += data->math.x_med * 0.115;
		data->math.y_min += data->math.y_med * 0.115;
		data->math.y_max = data->math.y_min + \
		(data->math.x_max - data->math.x_min) * HEIGHT / WIDTH;
	}
	render_fractal(data);
	return (SUCCESS);
}
