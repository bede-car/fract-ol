/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fractal_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 08:38:21 by bede-car          #+#    #+#             */
/*   Updated: 2023/01/21 21:11:38 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	check_fractal_set(int argc, char **argv, t_math *math)
{
	if (argc == 1)
		parameter_not_found();
	else
	{
		strtolower(argv[1]);
		if (is_mandelbrot(argc, argv) == SUCCESS)
		{
			math->fractal = mandelbrot;
			return ;
		}
		if (is_julia(argc, argv) == SUCCESS)
		{
			math->fractal = julia;
			math->julia_x = ft_atof(argv[2]);
			math->julia_y = ft_atof(argv[3]);
			return ;
		}
	}
	invalid_option();
}

void	strtolower(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		str[index] = ft_tolower(str[index]);
		index++;
	}
}

int	is_julia(int argc, char **argv)
{
	if (ft_strncmp(argv[1], "julia", 6) == 0 && argc == 4)
		if (ft_isnum(argv[2]) && ft_isnum(argv[3]))
			return (SUCCESS);
	if (ft_strncmp(argv[1], "julia", 6) == 0 && argc != 4)
		error_julia();
	return (ERROR);
}

int	is_mandelbrot(int argc, char **argv)
{
	if (ft_strncmp(argv[1], "mandelbrot", 11) == 0 && argc == 2)
		return (SUCCESS);
	if (ft_strncmp(argv[1], "mandelbrot", 11) == 0 && argc != 2)
		error_mandelbrot();
	return (ERROR);
}
