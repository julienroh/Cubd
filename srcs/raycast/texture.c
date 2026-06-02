/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfumeaux <mfumeaux@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 12:27:18 by mfumeaux          #+#    #+#             */
/*   Updated: 2026/06/02 15:07:33 by mfumeaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	select_texture(t_data *data)
{
	double wallX;
	if (data->side == 0)
	{
		wallX = data->player_y + data->perp_wall_dist * data->raydir_y;
		if (data->raydir_x > 0)
			data->selected_text = &data->tex_east;
		else
			data->selected_text = &data->tex_west;
	}
	else
	{
		wallX = data->player_y + data->perp_wall_dist * data->raydir_x;
		if (data->raydir_y > 0)
			data->selected_text = &data->tex_south;
		else
			data->selected_text = &data->tex_north;
	}
	wallX -= floor(wallX);
}

void draw_wall(t_data *data, int x, int start_y, int end_y)
{

	
}