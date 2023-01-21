/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:17:49 by bede-car          #+#    #+#             */
/*   Updated: 2023/01/20 21:14:52 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void render_fractal(t_data *data)
{
	data->math.pixel_x = 0;
	data->math.pixel_y = 0;
	init_math(&data->math);
	while (data->math.pixel_x < WIDTH)
	{
		while (data->math.pixel_y < HEIGHT)
		{
			complex_numbers(&data->math);
			my_mlx_pixel_put(&data->lib, data->math.pixel_x, data->math.pixel_y, 0x0000FF);
			//define_color(&data->math));
			data->math.pixel_y++;
		}
		data->math.pixel_x++;
	}
}
	
void	my_mlx_pixel_put(t_lib *lib, int x, int y, int color)
{
	char	*img_point;

	img_point = lib->add_img + (y * lib->line_length + \
	x * (lib->bits_per_pixel / 8));
	*(unsigned int*)img_point = color;
}

int define_color(t_math *math)
{
	math->fractal(math);
	printf("%d", math->interations);
	if(math->interations == math->max_interation)
	{
		return(0x0000FF);
	}
	else
		return(0xFFFFFF);
}
