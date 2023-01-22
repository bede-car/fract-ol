/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:36:12 by bede-car          #+#    #+#             */
/*   Updated: 2023/01/22 21:54:40 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	complex_numbers(t_math *math)
{
	math->complex_real = math->x_min + (math->pixel_x) * \
	((math->x_max - math->x_min) / WIDTH);
	math->complex_img = math->y_min + (math->pixel_y) * \
	((math->y_max - math->y_min) / HEIGHT);
}

void	mandelbrot(t_math *math)
{
	math->interations = 0;
	math->number_real = 0;
	math->number_img = 0;
	while (math->interations < math->max_interation)
	{
		math->x_square = math->number_real * math->number_real;
		math->y_square = math->number_img * math->number_img;
		math->number_img = 2 * math->number_real * math->number_img + \
		math->complex_img;
		math->number_real = math->x_square - math->y_square + \
		math->complex_real;
		if ((math->x_square + math->y_square) > 4)
			break ;
		math->interations++;
	}
}

void	julia(t_math *math)
{
	math->interations = 0;
	math->number_real = math->complex_real;
	math->number_img = math->complex_img;
	while (math->interations < math->max_interation)
	{
		math->x_square = math->number_real * math->number_real;
		math->y_square = math->number_img * math->number_img;
		math->number_img = (2 * math->number_real * math->number_img) - \
		math->julia_y;
		math->number_real = math->x_square - math->y_square + math->julia_x;
		if ((math->x_square + math->y_square) > 4)
			break ;
		math->interations++;
	}
}

void	init_math(t_math *math)
{
	math->x_min = -2;
	math->x_max = 2;
	math->y_min = -1.5;
	math->y_max = math->y_min + (math->x_max - math->x_min) * HEIGHT / WIDTH;
	math->max_interation = 300;
}
