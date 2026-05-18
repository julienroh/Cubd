/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfumeaux <mfumeaux@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:32:11 by haoky             #+#    #+#             */
/*   Updated: 2026/05/18 13:54:29 by mfumeaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_player(t_data *data)
{
	draw_square(data,
		(int)(data->player_x * TILE_SIZE),
		(int)(data->player_y * TILE_SIZE),
		0xFF0000);
}

void	draw_dir(t_data *data)
{
	double	curr_x;
	double	curr_y;
	int 	k;
	
	k = 0;
	curr_x = (data->player_x * TILE_SIZE) + (TILE_SIZE / 2);
	curr_y = (data->player_y * TILE_SIZE) + (TILE_SIZE / 2);
	while (k < 50)
	{
		img_pix_put(&data->mlx, (int)curr_x, (int)curr_y, 0x06C7DC);
		curr_x += data->player_dir_x;
		curr_y += data->player_dir_y;
		k++;
	}
}
