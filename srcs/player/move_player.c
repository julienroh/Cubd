/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haoky <haoky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:32:00 by haoky             #+#    #+#             */
/*   Updated: 2026/05/20 15:30:24 by haoky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_forward(t_data *data)
{
	double	new_y;

	new_y = data->player_y - MOVE_SPEED;
	if (data->map[(int)(new_y - PLAYER_RADIUS)][(int)data->player_x] != '1')
		data->player_y = new_y;
}

void	move_backward(t_data *data)
{
	double	new_y;

	new_y = data->player_y + MOVE_SPEED;
	if (data->map[(int)(new_y + PLAYER_RADIUS)][(int)data->player_x] != '1')
		data->player_y = new_y;
}

void	move_left(t_data *data)
{
	double	new_x;

	new_x = data->player_x - MOVE_SPEED;
	if (data->map[(int)data->player_y][(int)(new_x - PLAYER_RADIUS)] != '1')
		data->player_x = new_x;
}

void	move_right(t_data *data)
{
	double	new_x;

	new_x = data->player_x + MOVE_SPEED;
	if (data->map[(int)data->player_y][(int)(new_x + PLAYER_RADIUS)] != '1')
		data->player_x = new_x;
}
