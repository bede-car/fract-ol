/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:21:20 by bede-car          #+#    #+#             */
/*   Updated: 2023/01/03 21:31:48 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int keyboard_events(int keycode, t_mlx *mlx)
{
	if(keycode == XK_Escape)
		destroying_window(mlx);
	if(keycode == XK_a)
		printf("apertei o a\n");   
	printf("apertei aqui: %d\n", keycode);
	return(SUCCESS);
}

int mouse_events(int event, int x, int y, t_mlx *mlx)
{
	(void)mlx;
	if(event == 1)
	{
		printf("coordenada da janela %d %d\n", x, y);
		printf("apertei o lado esquerdo do mouse\n");
	}
	return(SUCCESS);
}