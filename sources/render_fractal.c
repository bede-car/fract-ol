/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:17:49 by bede-car          #+#    #+#             */
/*   Updated: 2023/01/20 18:33:41 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void render(t_data *data)
{
	data->math.pixel_x = 0;
	data->math.pixel_y = 0;
	while (data->math.pixel_x < WIDTH)
	{
		while (data->math.pixel_y < HEIGHT)
		{
			complex_numbers(&data->math);
			my_mlx_pixel_put(&data->lib, data->math.pixel_x, data->math.pixel_y, \
			define_color(&data->math));
			data->math.pixel_y++;
		}
		data->math.pixel_x++;
	}
}
	

int mandelbrot(double complex_real, double complex_img)
{

	//z
	return (SUCCESS);
}

int	julia(double complex_real, double complex_img)
{

    return (SUCCESS);
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
	
	math->fractal(math->complex_real, math->complex_img);
	
}

complex_numbers()
{

	
}