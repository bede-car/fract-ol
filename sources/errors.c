/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:58:14 by bede-car          #+#    #+#             */
/*   Updated: 2023/01/18 23:33:09 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int check_fractol_set(int argc, char ** argv)
{
    int index;
	if(argc >= 2 && argc <= 4)
	{
		index = 0;
		while(argv[1][index])
		{
			argv[1][index] = ft_tolower(argv[1][index]);
			index++;
		}
		if(ft_strncmp(argv[1], "mandelbrot", 11) == 0 && argc == 2)
			return(SUCCESS);
		if(ft_strncmp(argv[1], "julia", 6) == 0 && argc == 4)
			return(SUCCESS);
    }
    ft_printf(MSG0"\n"MSG1"\n"MSG2"\n"MSG3);
    return(ERROR);
}