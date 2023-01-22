/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:58:14 by bede-car          #+#    #+#             */
/*   Updated: 2023/01/22 13:05:49 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

void	invalid_option(void)
{
	ft_printf("This program renders 2 types of fractal set, ");
	ft_printf("you need to choose one of them.\n");
	ft_printf("\nOptions available: \n");
	ft_printf("\tMandelbrot\n\tJulia parameter1 parameter2\n\n");
	ft_printf("Exemples: \n");
	ft_printf("\t$./fractol mandelbrot\n");
	ft_printf("\t$./fractol julia 0.4 -0.6\n\n");
	ft_printf("Notes: Uppercase or lowercase letters are accepted, ");
	ft_printf("enjoy the view!\n\n");
	exit(ERROR);
}

void	parameter_not_found(void)
{
	ft_printf("\n>>>>> No parameter was provided ! <<<<<\n\n");
}

void	error_mandelbrot(void)
{
	ft_printf("\n>>>>> Argument is not expected for Mandelbrot set. <<<<<\n\n");
}

void	error_julia(void)
{
	ft_printf("\n>>>>>Julia's set needs 2 parameters as arguments.<<<<<\n\n");
}
