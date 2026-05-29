/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroh <jroh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 14:52:09 by haoky             #+#    #+#             */
/*   Updated: 2026/05/29 13:17:35 by jroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*  rotate angle of view using rotation matrice :
		x_new = x * cos(alpha) - y * sin(alpha)
		y_new = x * sin(alpha) + y * cos(alpha)
		alpha = angle of rotation, determining rot_speed.	*/

void	rotate_left(t_data *data)
{
	double	rot_speed;
	double 	old_player_dir_x;
	double	old_plane_x;

	old_player_dir_x = data->player_dir_x;
	old_plane_x = data->plane_x;
	rot_speed = -0.03;
	data->player_dir_x = data->player_dir_x * cos(rot_speed)
		- data->player_dir_y * sin(rot_speed);
	data->player_dir_y = old_player_dir_x * sin(rot_speed)
		+ data->player_dir_y * cos(rot_speed);
	data->plane_x = old_plane_x * cos(rot_speed)
		- data->plane_y * sin(rot_speed);
	data->plane_y = old_plane_x * sin(rot_speed)
		+ data->plane_y * cos(rot_speed);
}

void	rotate_right(t_data *data)
{
	double	rot_speed;
	double 	old_player_dir_x;
	double	old_plane_x;

	old_plane_x = data->plane_x;
	old_player_dir_x = data->player_dir_x;
	rot_speed = 0.02;
	data->player_dir_x = data->player_dir_x * cos(rot_speed)
		- data->player_dir_y * sin(rot_speed);
	data->player_dir_y = old_player_dir_x * sin(rot_speed)
		+ data->player_dir_y * cos(rot_speed);
	data->plane_x = old_plane_x * cos(rot_speed)
		- data->plane_y * sin(rot_speed);
	data->plane_y = old_plane_x * sin(rot_speed)
		+ data->plane_y * cos(rot_speed);
}
