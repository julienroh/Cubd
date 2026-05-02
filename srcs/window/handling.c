#include "cub3d.h"

int	handle_input(int keysym, t_data *data)
{
	int	i;

	i = 0;
	if (keysym == XK_Escape)
	{
		i = mlx_loop_end(data->mlx.mlx);
		if (i != 0)
			return i;
	}
	return (0);
}

int	handle_close(t_data *data)
{
	int	i;

	i = 0;
	i = mlx_loop_end(data->mlx.mlx);
	if (i != 0)
		return i;
	return (0);
}
