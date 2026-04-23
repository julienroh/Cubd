#include "cub3d.h"

int	handle_input(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx.mlx, data->mlx.win);
		mlx_loop_end(data->mlx.mlx);
	}
	return (0);
}

int	handle_close(t_data *data)
{
	mlx_destroy_window(data->mlx.mlx, data->mlx.win);
	mlx_loop_end(data->mlx.mlx);
	return (0);
}
