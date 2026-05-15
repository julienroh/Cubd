/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfumeaux <mfumeaux@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 14:00:16 by mfumeaux          #+#    #+#             */
/*   Updated: 2026/05/15 15:52:35 by mfumeaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*	Calculate screen ration from left (-1) to right (1).
	Then calculate the ray vector (raydir_x & raydir_y).
	*/
int	raycast(t_data *data)
{
	int x;

	x = 0;
	while (x < WIN_W)
	{
		data->screen_ratio = 2 * x / WIN_W -1;
		data->raydir_x = data->player_dir_x + data->plane_x
		* data->screen_ratio;
		data->raydir_y = data->player_dir_y + data->plane_y
		* data->screen_ratio;
		data->deltadist_x = 
		data->deltadist_y = 
		x++;
	}

	

	
}
