/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 19:12:42 by bede-car          #+#    #+#             */
/*   Updated: 2023/01/03 19:24:30 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* Main function, here I am checking the arguments passed by the users        */
/* ************************************************************************** */
#include "../includes/fractol.h"

int main(int argc, char** argv)
{
	if(check_fractol_set(argc, argv) == ERROR)
		return(ERROR);

    return(0);
}

//./fractol Mandelbrot
// argc = 2
// argv argv[0][] = ./fractol
// argv argv[1][] = Mandelbrot