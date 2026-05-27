/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haoky <haoky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:32:00 by haoky             #+#    #+#             */
/*   Updated: 2026/05/21 14:57:56 by haoky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	can_move(t_data *data, double x, double y)
{
	if (data->map[(int)(y - PLAYER_RADIUS)][(int)(x - PLAYER_RADIUS)] == '1')
		return (0);
	if (data->map[(int)(y - PLAYER_RADIUS)][(int)(x + PLAYER_RADIUS)] == '1')
		return (0);
	if (data->map[(int)(y + PLAYER_RADIUS)][(int)(x - PLAYER_RADIUS)] == '1')
		return (0);
	if (data->map[(int)(y + PLAYER_RADIUS)][(int)(x + PLAYER_RADIUS)] == '1')
		return (0);
	return (1);
}

void	move_forward(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player_x + data->player_dir_x * MOVE_SPEED;
	new_y = data->player_y + data->player_dir_y * MOVE_SPEED;
	if (can_move(data, new_x, new_y))
	{
		data->player_x = new_x;
		data->player_y = new_y;

	}
}

void	move_backward(t_data *data)
{
	double	new_y;
	double	new_x;

	new_x = data->player_x - data->player_dir_x * MOVE_SPEED;
	new_y = data->player_y - data->player_dir_y * MOVE_SPEED;
	if (can_move(data, new_x, new_y))
	{
		data->player_x = new_x;
		data->player_y = new_y;
	}
}

void	move_left(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player_x + data->player_dir_y * MOVE_SPEED;
	new_y = data->player_y + (-data->player_dir_x) * MOVE_SPEED;
	if (can_move(data, new_x, new_y))
	{
		data->player_x = new_x;
		data->player_y = new_y;
	}
}

void	move_right(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player_x + (-data->player_dir_y) * MOVE_SPEED;
	new_y = data->player_y + data->player_dir_x * MOVE_SPEED;
	if (can_move(data, new_x, new_y))
	{
		data->player_x = new_x;
		data->player_y = new_y;
	}
}
