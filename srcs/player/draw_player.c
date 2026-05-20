/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haoky <haoky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:32:11 by haoky             #+#    #+#             */
/*   Updated: 2026/05/20 14:07:45 by haoky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_player(t_data *data)
{
	draw_square(data,
		(int)data->player_x * TILE_SIZE,
		(int)data->player_y * TILE_SIZE,
		0xFF0000);
}
