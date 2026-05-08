/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haoky <haoky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:23:17 by haoky             #+#    #+#             */
/*   Updated: 2026/05/08 12:09:42 by haoky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_square(t_data *data, int start_x, int start_y, int color)
{
	int	x;
	int	y;

	y = start_y;
	while (y < start_y + TILE_SIZE)
	{
		x = start_x;
		while (x < start_x + TILE_SIZE)
		{
			img_pix_put(&data->mlx, x, y, color);
			x++;
		}
		y++;
	}
}

void	img_pix_put(t_mlx *mlx, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
		return ;
	pixel = mlx->addr + (y * mlx->line_len + x * (mlx->bits_per_pixel / 8));
	*(int *)pixel = color;
}

int	rgb_to_int(t_color color)
{
	return ((color.r << 16) | (color.g << 8) | color.b);
}
