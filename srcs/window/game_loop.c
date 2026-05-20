/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haoky <haoky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 13:43:17 by haoky             #+#    #+#             */
/*   Updated: 2026/05/20 14:51:38 by haoky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	game_loop(t_data *data)
{
	if (data->key_w)
		move_forward(data);
	if (data->key_s)
		move_backward(data);
	if (data->key_a)
		move_left(data);
	if (data->key_d)
		move_right(data);
	if (data->left)
		rotate_left(data);
	if (data->right)
		rotate_right(data);
	render_frame(data);
	return (0);
}
