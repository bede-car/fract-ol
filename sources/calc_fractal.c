/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:36:12 by bede-car          #+#    #+#             */
/*   Updated: 2023/01/20 20:54:23 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void complex_numbers(t_math *math)
{
    math->complex_real = math->x_min + (math->pixel_x) * \
    ((math->x_max - math->x_min) / WIDTH);
    //Xv = Xvmin + (Xw -  Xwmin) * ((Xvmax - Xvmin) / (Xwmax - Xwmin))
    //Xv = Xvmin + (Xw -  0) * ((Xvmax - Xvmin) / (Xwmax - 0) )
    math->complex_img = math->y_min + (math->pixel_y) * \
    ((math->y_max - math->y_min) / HEIGHT);
    //Yv = Yvmin + (Yw -  Ywmin) * ((Yvmax - Yvmin) / (Ywmax - Ywmin))	
}

void mandelbrot(t_math *math)
{
    math->interations = 0;
    math->number_real = 0;
    math->number_img = 0;
    while(math->interations < math->max_interation)
    {
        math->x_square = math->number_real * math->number_real;
        math->y_square = math->number_img * math->number_img;
        math->number_real = math->x_square - math->y_square + math->complex_real;
        math->number_img = 2 * math->number_real * math->number_img + math->complex_img;
        if((math->x_square + math->y_square) > 4)
            break;
        math->interations++;       
    }
    //z= z² + (complex_real - complex_img)
    //x = x² - y² + a --> 
    //y = 2 * x * y + b
    //(x² + y²) > 4
}

void	julia(t_math *math)
{
    (void)math;
}

void init_math(t_math *math)
{
    math->x_min = -2;
    math->x_max = 2;
    math->y_min = -1;
    math->y_max = 1;
    math->max_interation = 100;
}

