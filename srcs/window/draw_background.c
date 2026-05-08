/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haoky <haoky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:17:06 by haoky             #+#    #+#             */
/*   Updated: 2026/05/08 11:23:15 by haoky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
