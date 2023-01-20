/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fractal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 08:38:21 by bede-car          #+#    #+#             */
/*   Updated: 2023/01/20 11:35:11 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int check_fractol_set(int argc, char ** argv)
{
    int index;
	if (argc == 1)
	parameter_not_found();
	else
	{
	index = 0;
 	while(argv[1][index])
		{
			argv[1][index] = ft_tolower(argv[1][index]);
 			index++;
 		}
	if(is_mandelbrot(argc, argv) == SUCCESS)
		return(SUCCESS);
	if(is_julia(argc, argv) == SUCCESS)
		return(SUCCESS);			
	}
	invalid_option();
	return(ERROR);
}

int	is_julia(int argc, char **argv)
{
	if(ft_strncmp(argv[1], "julia", 6) == 0 && argc == 4)
		//if()
 			return(SUCCESS);
	if(ft_strncmp(argv[1], "julia", 6) == 0 && argc != 4)
		error_julia();
	return (ERROR);
}

int	is_mandelbrot(int argc, char **argv)
{
	if(ft_strncmp(argv[1], "mandelbrot", 11) == 0 && argc == 2)
 		return(SUCCESS);
	if(ft_strncmp(argv[1], "mandelbrot", 11) == 0 && argc != 2)
		error_mandelbrot();
	return (ERROR);
}


//primeira versão de tratativa de erro
// int check_fractol_set(int argc, char ** argv)
// {
//     int index;
// 	if(argc >= 2 && argc <= 4)
// 	{
// 		index = 0;
// 		while(argv[1][index])
// 		{
// 			argv[1][index] = ft_tolower(argv[1][index]);
// 			index++;
// 		}
// 		if(ft_strncmp(argv[1], "mandelbrot", 11) == 0 && argc == 2)
// 			return(SUCCESS);
// 		if(ft_strncmp(argv[1], "julia", 6) == 0 && argc == 4)
// 			return(SUCCESS);
//     }

//     ft_printf(MSG0"\n"MSG1"\n"MSG2"\n"MSG3);
//     return(ERROR);
// }