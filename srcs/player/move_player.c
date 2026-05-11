/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haoky <haoky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:32:00 by haoky             #+#    #+#             */
/*   Updated: 2026/05/11 13:51:10 by haoky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_forward(t_data *data)
{
	if (data->map[(int)data->player_y - 1][(int)data->player_x] != '1')
		data->player_y -= 0.03;
}

void	move_backward(t_data *data)
{
	if (data->map[(int)data->player_y + 1][(int)data->player_x] != '1')
		data->player_y += 0.03;
}

void	move_left(t_data *data)
{
	if (data->map[(int)data->player_y][(int)data->player_x - 1] != '1')
		data->player_x -= 0.03;
}

void	move_right(t_data *data)
{
	if (data->map[(int)data->player_y][(int)data->player_x + 1] != '1')
		data->player_x += 0.03;
}
