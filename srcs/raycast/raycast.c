/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfumeaux <mfumeaux@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 14:00:16 by mfumeaux          #+#    #+#             */
/*   Updated: 2026/06/02 12:20:45 by mfumeaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	initialize_sidedist_dda(t_data *data)
{
	if (data->raydir_x > 0)
	{
		data->stepx = 1;
		data->sidedist_x = ((data->map_x + 1) - data->player_x)
			* data->deltadist_x;
	}
	else if (data->raydir_x < 0)
	{
		data->stepx = -1;
		data->sidedist_x = (data->player_x - (data->map_x))
			* data->deltadist_x;
	}
	if (data->raydir_y > 0)
	{
		data->stepy = 1;
		data->sidedist_y = ((data->map_y + 1) - data->player_y)
			* data->deltadist_y;
	}
	else if (data->raydir_y < 0)
	{
		data->stepy = -1;
		data->sidedist_y = (data->player_y - (data->map_y))
			* data->deltadist_y;
	}
}

/*	Calculate screen ratio from left (-1) to right (1).
	Calculate the ray vector (raydir_x & raydir_y) (slope of the ray).
	Calculate sidedist X and Y : shortest distance to the nearest wall.
	Calculate deltadist X and Y : distance of the ray to travel 1 grid unit.
	Map_x & Map_y are the current tile the player is on.
	step is to tell DDA in which direction to go.
	*/
static void	initialize_dda_vars(t_data *data, int x)
{
	//data->screen_ratio = 2 * x / WIN_W - 1;
	data->screen_ratio = 2.0 * x / (double)WIN_W - 1.0;
	data->raydir_x = data->player_dir_x + data->plane_x
		* data->screen_ratio;
	data->raydir_y = data->player_dir_y + data->plane_y
		* data->screen_ratio;
	data->deltadist_x = fabs(1 / data->raydir_x);
	data->deltadist_y = fabs(1 / data->raydir_y);
	if (data->raydir_x == 0)
		data->deltadist_x = 1e30;
	else
		data->deltadist_x = fabs(1 / data->raydir_x);
	data->map_x = (int)data->player_x;
	data->map_y = (int)data->player_y;
	initialize_sidedist_dda(data);
}

static void	dda(t_data *data)
{
	while (data->hit == 0)
	{
		if (data->sidedist_x < data->sidedist_y)
		{
			data->map_x += data->stepx;
			data->sidedist_x += data->deltadist_x;
			data->side = 0;
		}
		else
		{
			data->map_y += data->stepy;
			data->sidedist_y += data->deltadist_y;
			data->side = 1;
		}
		if (data->map[(int)data->map_y][(int)data->map_x] == '1')
			data->hit = 1;
	}
}

static void	wall_projection(t_data *data, int x)
{
	int	y;

	data->line_height = (int)(WIN_H / data ->perp_wall_dist);
	data->draw_start = -(data->line_height) / 2 + WIN_H / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = data->line_height / 2 + WIN_H / 2;
	if (data->draw_end >= WIN_H)
		data->draw_end = WIN_H - 1;
	y = data->draw_start;
	while (y <= data->draw_end)
	{
		img_pix_put(&data->mlx, x, y, 0x007F00);
		// if (data->side == 1)
		// 	img_pix_put(&data->mlx, x, y, 0x007F00);
		// else
		// 	img_pix_put(&data->mlx, x, y, 0x00FF00);
		y++;
	}
}

int	raycast(t_data *data)
{
	int	x;

	x = 0;
	while (x < WIN_W)
	{
		data->hit = 0;
		data->side = 0;
		initialize_dda_vars(data, x);
		dda(data);
		if (data->side == 0)
			data->perp_wall_dist = (data->sidedist_x - data->deltadist_x);
		else
			data->perp_wall_dist = (data->sidedist_y - data->deltadist_y);
		wall_projection(data, x);
		x++;
	}
	return (0);
}
