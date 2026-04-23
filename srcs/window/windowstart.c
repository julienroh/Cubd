#include "cub3d.h"

void	img_pix_put(t_mlx *mlx, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
		return ;
	pixel = mlx->addr + (y * mlx->line_len + x * (mlx->bits_per_pixel / 8));
	*(int *)pixel = color;
}

void	start(t_data *data)
{
	data->mlx.mlx = mlx_init(); 
	if (!data->mlx.mlx)
		return ;
	data->mlx.win = mlx_new_window(data->mlx.mlx, WIN_W, WIN_H, "LoupCaillou");
	if (!data->mlx.win)
		return ;
	data->mlx.img = mlx_new_image(data->mlx.mlx, WIN_W, WIN_H);
	if (!data->mlx.img)
		return ;
	data->mlx.addr = mlx_get_data_addr(data->mlx.img, &data->mlx.bits_per_pixel,
			&data->mlx.line_len, &data->mlx.endian);
	for(int i = 0; i< WIN_W; i++)
	{
			for(int j = 0; j < WIN_H; j++)
			{
				if (j%15 == 0)
					img_pix_put(&data->mlx, j, i, 0xFF4E4FEE);

			}
		img_pix_put(&data->mlx, 40, i, 0xFF4E4FEE);
	}
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img, 0, 0);
	mlx_key_hook(data->mlx.win, &handle_input, data);
	mlx_hook(data->mlx.win, DestroyNotify, StructureNotifyMask,
		&handle_close, data);
	mlx_loop(data->mlx.mlx);
	clean(data);
}



