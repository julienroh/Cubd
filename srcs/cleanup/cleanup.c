#include "cub3d.h"

void	clean(t_data *data)
{
	mlx_destroy_image(data->mlx.mlx, data->mlx.img);
	data->mlx.img = NULL;
	mlx_destroy_display(data->mlx.mlx);
	free(data->mlx.mlx);
	data->mlx.mlx = NULL;
	//inserer les free du parsing ici.
}
