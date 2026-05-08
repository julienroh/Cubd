/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haoky <haoky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:31:32 by haoky             #+#    #+#             */
/*   Updated: 2026/05/08 11:57:39 by haoky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '0')
				draw_square(data, j * TILE_SIZE, i * TILE_SIZE, 0x000000);
			else if (data->map[i][j] == '1')
				draw_square(data, j * TILE_SIZE, i * TILE_SIZE, 0xFFFFFF);
			else if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
				|| data->map[i][j] == 'E' || data->map[i][j] == 'W')
				draw_square(data, j * TILE_SIZE, i * TILE_SIZE, 0xFF0000);
			j++;
		}
		i++;
	}
}
