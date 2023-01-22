/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 23:51:24 by bede-car          #+#    #+#             */
/*   Updated: 2023/01/21 21:11:56 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	keyboard_events(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		destroying_window(&data->lib);
	return (SUCCESS);
}

int	mouse_events(int event, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (event != 4 && event != 5)
		return (ERROR);
	if (event == 5)
	{
		data->math.x_max *= 1.115;
		data->math.x_min *= 1.115;
		data->math.y_max *= 1.115;
		data->math.y_min *= 1.115;
	}
	else if (event == 4)
	{
		data->math.x_max *= 0.885;
		data->math.x_min *= 0.885;
		data->math.y_max *= 0.885;
		data->math.y_min *= 0.885;
	}
	render_fractal(data);
	return (SUCCESS);
}
