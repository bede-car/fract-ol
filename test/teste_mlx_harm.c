#include <math.h>
#include <mlx.h>
#include <stdlib.h>

typedef struct s_mlx
{
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int        bpp;
    int        line_len;
    int        endian;
}            t_mlx;

void    pixel_put(t_mlx *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
    *(unsigned int *)dst = color;
}

int    main(void)
{
    t_mlx mlx;

    mlx.mlx = mlx_init();
    mlx.win = mlx_new_window(mlx.mlx, 800, 800, "janela");
    mlx.img = mlx_new_image(mlx.mlx, 800, 800);
    mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.line_len, &mlx.endian);

    pixel_put(&mlx, 400, 400, 0xFFF000);
    mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
    mlx_loop(mlx.mlx);
    
    return (0);
}