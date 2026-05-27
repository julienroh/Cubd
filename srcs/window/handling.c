/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haoky <haoky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 12:00:37 by mfumeaux          #+#    #+#             */
/*   Updated: 2026/05/20 14:49:34 by haoky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	handle_key_press(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_loop_end(data->mlx.mlx);
	else if (keysym == XK_w)
		data->key_w = 1;
	else if (keysym == XK_s)
		data->key_s = 1;
	else if (keysym == XK_a)
		data->key_a = 1;
	else if (keysym == XK_d)
		data->key_d = 1;
	else if (keysym == XK_Left)
		data->left = 1;
	else if (keysym == XK_Right)
		data->right = 1;
	return (0);
}

int	handle_key_release(int keysym, t_data *data)
{
	if (keysym == XK_w)
		data->key_w = 0;
	else if (keysym == XK_s)
		data->key_s = 0;
	else if (keysym == XK_a)
		data->key_a = 0;
	else if (keysym == XK_d)
		data->key_d = 0;
	else if (keysym == XK_Left)
		data->left = 0;
	else if (keysym == XK_Right)
		data->right = 0;
	return (0);
}

int	handle_close(t_data *data)
{
	int	i;

	i = 0;
	i = mlx_loop_end(data->mlx.mlx);
	if (i != 0)
		return (i);
	return (0);
}
