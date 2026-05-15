/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfumeaux <mfumeaux@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 13:43:17 by haoky             #+#    #+#             */
/*   Updated: 2026/05/12 14:33:58 by mfumeaux         ###   ########.fr       */
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
		rotate_left(data);
	if (data->key_d)
		rotate_right(data);
	render_frame(data);
	return (0);
}
