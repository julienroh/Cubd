/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfumeaux <mfumeaux@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 12:27:18 by mfumeaux          #+#    #+#             */
/*   Updated: 2026/06/07 15:50:49 by mfumeaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*	wall_x : Where the ray hit the wall, between 0 and 1
	floor = remove what's after the ',' Ex : 14.43 -> 14.
	tex_x : conversion of wall_x in a pixel of the texture.
*/
void	select_texture(t_data *data)
{
	if (data->side == 0)
	{
		data->wall_x = data->player_y + data->perp_wall_dist * data->raydir_y;
		if (data->raydir_x > 0)
			data->selected_text = &data->tex_east;
		else
			data->selected_text = &data->tex_west;
	}
	else
	{
		data->wall_x = data->player_x + data->perp_wall_dist * data->raydir_x;
		if (data->raydir_y > 0)
			data->selected_text = &data->tex_south;
		else
			data->selected_text = &data->tex_north;
	}
	data->wall_x -= floor(data->wall_x);
	data->tex_x = (int)(data->wall_x * data->selected_text->width);
}

