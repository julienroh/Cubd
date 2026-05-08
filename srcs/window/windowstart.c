/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windowstart.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haoky <haoky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 12:00:39 by mfumeaux          #+#    #+#             */
/*   Updated: 2026/05/07 15:12:43 by haoky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	rgb_to_int(t_color color)
{
	return ((color.r << 16) | (color.g << 8) | color.b);
}

static void	img_pix_put(t_mlx *mlx, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
		return ;
	pixel = mlx->addr + (y * mlx->line_len + x * (mlx->bits_per_pixel / 8));
	*(int *)pixel = color;
}

void	draw_background(t_data *data)
{
	int	x;
	int	y;
	int	floor_color;
	int	ceiling_color;

	floor_color = rgb_to_int(data->floor);
	ceiling_color = rgb_to_int(data->ceiling);
	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			if (y < WIN_H / 2)
				img_pix_put(&data->mlx, x, y, ceiling_color);
			else
				img_pix_put(&data->mlx, x, y, floor_color);
			x++;
		}
		y++;
	}
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
	draw_background(data);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img, 0, 0);
	mlx_key_hook(data->mlx.win, &handle_input, data);
	mlx_hook(data->mlx.win, DestroyNotify, StructureNotifyMask,
		&handle_close, data);
	mlx_loop(data->mlx.mlx);
	clean(data);
}
