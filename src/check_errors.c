/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 08:45:54 by bede-car          #+#    #+#             */
/*   Updated: 2023/01/03 19:24:35 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	check_fractol_set(int argc, char ** argv)
{
	int index;
	if(argc < 2 || argc > 4)
	{
		printf(MSG);
		return(ERROR);
	}
	index = 0;
	while(argv[1][index])
	{
		argv[1][index] = ft_tolower(argv[1][index]);
		index++;
	}
	if(ft_strncmp(argv[1], "mandelbrot", 11) == 0)
		return(SUCCESS);
	if(ft_strncmp(argv[1], "julia", 6) == 0)
		return(SUCCESS);
	return(ERROR);
}

// ./fractol Mandelbrot
// argc = 2
// argv argv[0][] = ./fractol
// argv argv[1][] = Mandelbrot
// if(<argumento> <operador> <argumento>)

//testando a quantidade de argumentos de entrada
//testando se a entrada for a chamada do mandelbrot --> argv[1] 
//testando se a entrada for a chamada for julia + 2 parametros




















// int ft_check_fractol_set(int argc, char **argv)
// {
//     if(argc != 2)
//     {
//         ft_putstr_fd("Error\n",2);
//         return (ERROR);
//     }
//     if(ft_strncmp(argv[1], "Mandelbrot", 11) == 0)
//     {
//         // printf("passou aqui mano\n");
//         return(SUCCESS);
//         //posso chamar a janela e desenhar fractal Mandelbrot
//     }
//     if(ft_strncmp(argv[1], "teste", 6) == 0)
//     {
//         return(SUCCESS);
//         //teste
//     }
//     else if(ft_strncmp(argv[1], "Julia", 5) == 0)
// 	{
//         // printf("passou aqui mina\n");
//         return(SUCCESS);
//         //posso chamar a janela e desenhar fractal Julia x x 
//     }
//     else
//     {
//         ft_putstr_fd("Invalid Fractal! Try one of this options:\nMandelbrot\nJulia\n", 2);
//     }
//     return(ERROR);
// }