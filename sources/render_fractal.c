/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:17:49 by bede-car          #+#    #+#             */
/*   Updated: 2023/01/20 22:31:20 by bede-car         ###   ########.fr       */
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
		data->math.pixel_y = 0;
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
	
void	my_mlx_pixel_put(t_lib *lib, int x, int y, int color)
{
	char	*img_point;

	img_point = lib->add_img + (y * lib->line_length + x * (lib->bits_per_pixel / 8));
	*(unsigned int*)img_point = color;
}

int define_color(t_math *math)
{
	int rgb[3];
	math->fractal(math);
	if(math->interations == math->max_interation)
	{
		return(0x000000);
	}
	rgb[0] = sin(0.14 * math->interations + 5.5) * 127 + 128;
	rgb[1] = sin(0.14 * math->interations + 5.7) * 127 + 128;
	rgb[2] = sin(0.14 * math->interations + 5.9) * 127 + 128;
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

// int	set_color(int i, t_mlx *mlx)
// {
// 	int	rbg[3];

// 	if (mlx->color == 1)
// 	{
// 		rbg[0] = sin(0.1 * i + 0) * 127 + 128;
// 		rbg[1] = sin(0.1 * i + 2) * 127 + 128;
// 		rbg[2] = sin(0.1 * i + 4) * 127 + 128;
// 	}
// 	else if (mlx->color == 2)
// 	{
// 		rbg[0] = sin(0.1 * i + 5) * 127 + 128;
// 		rbg[1] = sin(0.1 * i + 6) * 127 + 128;
// 		rbg[2] = sin(0.1 * i + 7) * 127 + 128;
// 	}
// 	else if (mlx->color == 3)
// 	{
// 		rbg[0] = sin(0.1 * i + 8) * 127 + 128;
// 		rbg[1] = sin(0.1 * i + 9) * 127 + 128;
// 		rbg[2] = sin(0.1 * i + 0) * 127 + 128;
// 	}
// 	if (mlx->color == 4)
// 		mlx->color = 1;
// 	return (rbg[0] << 16 | rbg[1] << 8 | rbg[2]);
// }