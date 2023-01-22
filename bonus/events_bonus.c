/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:57:28 by bede-car          #+#    #+#             */
/*   Updated: 2023/01/21 22:06:08 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void move_key_arrow(int keycode, t_data *data)
{
	double	x_med;
	double	y_med;
	x_med = (data->math.x_max - data->math.x_min);
	y_med = (data->math.y_max - data->math.y_min);	
	if (keycode < 65360 && keycode > 65365)
		return ;
	if (keycode== XK_Left)
	{
		data->math.x_min += x_med * 0.115;
		data->math.x_max += x_med * 0.115;
	}
	else if (keycode== XK_Right)
	{
		data->math.x_min -= x_med * 0.115;
		data->math.x_max -= x_med * 0.115;
	}
	else if (keycode== XK_Down)
	{
		data->math.y_min -= y_med * 0.115;
		data->math.y_max -= y_med * 0.115;
	}
	else if (keycode== XK_Up)
	{
		data->math.y_min += y_med * 0.115;
		data->math.y_max += y_med * 0.115;
	}
	render_fractal(data);
}

int	keyboard_events(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		destroying_window(&data->lib);
	move_key_arrow(keycode, data);
	return (SUCCESS);
}

int	mouse_events(int event, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	double	x_med;
	double	y_med;
	x_med = (data->math.x_max - data->math.x_min);
	y_med = (data->math.y_max - data->math.y_min);	
	if (event != 4 && event != 5)
		return (ERROR);
	if (event == 5)
	{
		data->math.x_max += x_med * 0.115;
		data->math.x_min -= x_med * 0.115;
		data->math.y_min -= y_med * 0.115;
		data->math.y_max = data->math.y_min + (data->math.x_max - data->math.x_min) * HEIGHT / WIDTH;
	}
	else if (event == 4)
	{
		data->math.x_max -= x_med * 0.115;
		data->math.x_min += x_med * 0.115;
		data->math.y_min += y_med * 0.115;
		data->math.y_max = data->math.y_min + (data->math.x_max - data->math.x_min) * HEIGHT / WIDTH;
	}
	render_fractal(data);
	return (SUCCESS);
}