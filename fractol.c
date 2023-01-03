/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:21:41 by bede-car          #+#    #+#             */
/*   Updated: 2022/12/30 09:22:38 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"
#include "./libft/libft.h"

int ft_check_fractol_set(int argc, char **argv)
{
    if(argc != 2)
    {
        ft_putstr_fd("Error\n",2);
        return (ERROR);
    }
    if(ft_strncmp(argv[1], "Mandelbrot", 10) == 0)
    {
        printf("passou aqui mano\n");
        return(SUCCESS);
        //posso chamar a janela e desenhar fractal Mandelbrot
    }
    if(ft_strncmp(argv[1], "teste", 5) == 0)
    {
        return(SUCCESS);
        //teste
    }
    else if(ft_strncmp(argv[1], "Julia", 5) == 0)
    {
        printf("passou aqui mina\n");
        return(SUCCESS);
        //posso chamar a janela e desenhar fractal Julia x x 
    }
    else
    {
        ft_putstr_fd("Invalid Fractal! Try one of this options:\nMandelbrot\nJulia\n", 2);
    }
    return(SUCCESS);
}

void ft_my_pixel_put(t_mlx *cavalinho)
{
    char *ptr;
    ptr = cavalinho->add_img + (cavalinho->y * cavalinho->size_line + cavalinho->x * (cavalinho->bit_per_pixel / 8));
    *(unsigned int*)ptr = 0x42f560;

}

int main (int argc, char **argv)
{
    t_mlx   cavalinho;

    ft_check_fractol_set(argc, argv);
    cavalinho.mlx = mlx_init();
    cavalinho.win = mlx_new_window(cavalinho.mlx, 650, 650, "cavalinho");
    cavalinho.img = mlx_new_image(cavalinho.mlx, 650, 650);
    cavalinho.add_img = mlx_get_data_addr(cavalinho.img, &cavalinho.bit_per_pixel, &cavalinho.size_line, &cavalinho.endian);
    cavalinho.x = 40;
    cavalinho.y = 40;
    while(cavalinho.x < 60)
    {
       ft_my_pixel_put(&cavalinho);
        cavalinho.x++;
        cavalinho.y++;
    }
    mlx_put_image_to_window(cavalinho.mlx, cavalinho.win, cavalinho.img, 50, 50);
    mlx_loop(cavalinho.mlx);
}
 
