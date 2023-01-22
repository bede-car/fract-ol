/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fractal_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:17:49 by bede-car          #+#    #+#             */
/*   Updated: 2023/01/22 21:35:24 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

int	render_fractal(t_data *data)
{
	data->math.pixel_x = 0;
	data->math.pixel_y = 0;
	while (data->math.pixel_x < WIDTH)
	{
		data->math.pixel_y = 0;
		while (data->math.pixel_y < HEIGHT)
		{
			complex_numbers(&data->math);
			my_mlx_pixel_put(&data->lib, data->math.pixel_x, \
			data->math.pixel_y, define_color(&data->math));
			data->math.pixel_y++;
		}
		data->math.pixel_x++;
	}
	mlx_put_image_to_window(data->lib.mlx, data->lib.win, data->lib.img, 0, 0);
	return (SUCCESS);
}

void	my_mlx_pixel_put(t_lib *lib, int x, int y, int color)
{
	char	*img_point;

	img_point = lib->add_img + (y * lib->line_length + x * \
	(lib->bits_per_pixel / 8));
	*(unsigned int *)img_point = color;
}

int	define_color(t_math *math)
{
	math->fractal(math);
	if (math->interations == math->max_interation)
		return (0x000000);
	return (change_color(math));
}

int	change_color(t_math *math)
{
	int	rgb[3];

	math->fractal(math);
	if (math->color == 1)
	{
	rgb[0] = sin(0.1 * math->interations + 5) * 125 + 126;
	rgb[1] = sin(0.1 * math->interations + 6) * 125 + 126;
	rgb[2] = sin(0.1 * math->interations + 7) * 125 + 126;
	}
	else if (math->color == 2)
	{
	rgb[0] = sin(0.1 * math->interations + 58) * 126 + 127;
	rgb[1] = sin(0.1 * math->interations + 10) * 126 + 127;
	rgb[2] = sin(0.1 * math->interations + 100) * 126 + 127;
	}
	else if (math->color == 3)
	{
	rgb[0] = sin(0.05 * math->interations + 70) * 124 + 125;
	rgb[1] = sin(0.05 * math->interations + 100) * 124 + 125;
	rgb[2] = sin(0.05 * math->interations + 500) * 124 + 125;
	}
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}
