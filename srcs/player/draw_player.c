/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroh <jroh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:32:11 by haoky             #+#    #+#             */
/*   Updated: 2026/05/29 15:27:48 by jroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	draw_player_square(t_data *data, int st_x, int st_y, int color)
{
	int	x;
	int	y;

	y = st_y;
	while (y < st_y + PLAYER_DRAW_SIZE)
	{
		x = st_x;
		while (x < st_x + PLAYER_DRAW_SIZE)
		{
			img_pix_put(&data->mlx, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_player(t_data *data)
{
	int	x;
	int	y;

	x = (int)(data->player_x * MMAP_SIZE);
	y = (int)(data->player_y * MMAP_SIZE);
	draw_player_square(data, x - PLAYER_DRAW_SIZE / 2,
		y - PLAYER_DRAW_SIZE / 2, 1234567);
}

void	draw_dir(t_data *data)
{
	double	curr_x;
	double	curr_y;
	int		k;

	k = 0;
	curr_x = (data->player_x * MMAP_SIZE) + (PLAYER_RADIUS);
	curr_y = (data->player_y * MMAP_SIZE) + (PLAYER_RADIUS);
	while (k < MMAP_SIZE * 2)
	{
		img_pix_put(&data->mlx, (int)curr_x, (int)curr_y, 0xFF4444);
		curr_x += data->player_dir_x;
		curr_y += data->player_dir_y;
		k++;
	}
}
