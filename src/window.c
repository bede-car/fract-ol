/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:45:16 by bede-car          #+#    #+#             */
/*   Updated: 2023/01/03 22:19:33 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int creating_window(t_mlx *mlx)
{
	mlx->mlx=mlx_init();
	if(mlx->mlx == NULL)
		return(ERROR);
    mlx->win=mlx_new_window(mlx->mlx, 600, 600, "bia rainha");
	if(mlx->win == NULL)
	{
		free(mlx->mlx);
		return(ERROR);
	}
	return(SUCCESS);
}

int destroying_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	exit(SUCCESS);
}

//criar imagem
