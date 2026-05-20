/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haoky <haoky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:32:00 by haoky             #+#    #+#             */
/*   Updated: 2026/05/20 16:15:31 by haoky            ###   ########.fr       */
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
		data->player_y = new_y;
		data->player_x = new_x;

	}
}

void	move_backward(t_data *data)
{
	double	new_y;

	new_y = data->player_y + MOVE_SPEED;
	if (can_move(data, data->player_x, new_y))
		data->player_y = new_y;
}

void	move_left(t_data *data)
{
	double	new_x;

	new_x = data->player_x - MOVE_SPEED;
	if (can_move(data, new_x, data->player_y))
		data->player_x = new_x;
}

void	move_right(t_data *data)
{
	double	new_x;

	new_x = data->player_x + MOVE_SPEED;
	if (can_move(data, new_x, data->player_y))
		data->player_x = new_x;
}
