/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   learning_mlx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:58:30 by bede-car          #+#    #+#             */
/*   Updated: 2022/11/13 15:09:08 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

void ft_drawing_square(int x, int y, void *mlx, void *mlx_win, int color)
{
	int xi;
	int yi;
	xi = x;
	yi = y;

	while(xi <= (x+50))
	{	
		mlx_pixel_put(mlx, mlx_win, xi, y, color);
		mlx_pixel_put(mlx, mlx_win, xi, y+50, color);
		xi++;
		color = color + 0x010101;
	}
	while(yi <= (y+50))
	{
		mlx_pixel_put(mlx, mlx_win, x, yi, color);
		mlx_pixel_put(mlx, mlx_win, x+50, yi, color);
		yi++;
		color = color + 0x010101;
	}
	
}

// struct	s_var_mlx
// {
// 	void *mlx;
// 	void *mlx_win;
// };

// struct s_var_mlx mlx;
// t_var_mlx mlx;
// int mlx;
// char mlx;

// typedef struct s_var_mlx t_var_mlx;

// void ft_drawing_triangle(int x, int y, void *mlx, void *mlx_win, int color)
// {
// 	int xi;
// 	int yi;
// 	xi = x;
// 	yi = y;

// 	while(xi <= (x+20))
// 	{	
// 		mlx_pixel_put(mlx, mlx_win, xi, y, color);
// 		mlx_pixel_put(mlx, mlx_win, xi, y+20, color);
// 		xi++;
// 		color = color + 1000;
// 	}
// 	while(yi <= (y+20))
// 	{
// 		mlx_pixel_put(mlx, mlx_win, x, yi, color);
// 		mlx_pixel_put(mlx, mlx_win, x+20, yi, color);
// 		yi++;
// 		color = color + 1000;
// 	}
	
// }

int main(void)
{

	void *mlx_win;
	void *mlx;
    void *img;
	
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "test");
	
	
	ft_drawing_square(10, 200, mlx, mlx_win, 0x42f560);
	ft_drawing_square(200, 10, mlx, mlx_win, 0xf59c42);
	ft_drawing_square(400, 400, mlx, mlx_win, 0xf542aa);
    img = mlx_new_image(mlx, 100, 100);
	mlx_loop(mlx);

	//events
	// mlx_hook(mlx_win, 02, (1L<<0), ft_print_key, var_mlx)
	
	return (0);
}

