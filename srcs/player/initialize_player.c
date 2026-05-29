/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroh <jroh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 15:47:38 by haoky             #+#    #+#             */
/*   Updated: 2026/05/29 15:30:20 by jroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* Assign correct vector depending of the player spawn orientation 
Nb :  0.66 = FOV of the plane camera. */

static void	set_vector_dir_plane(t_data *data, char direction)
{
	if (direction == 'N')
	{
		data->player_dir_y = -1;
		data->plane_x = 0.66;
	}
	else if (direction == 'S')
	{
		data->player_dir_y = 1;
		data->plane_x = -0.66;
	}
	else if (direction == 'W')
	{
		data->player_dir_x = -1;
		data->plane_y = -0.66;
	}
	else if (direction == 'E')
	{
		data->player_dir_x = 1;
		data->plane_y = 0.66;
	}
}

/* Assign vectors and position of player. */
static int	set_player_dir(t_data *data, char direction, int x, int y)
{
	data->map[y][x] = '0';
	if (data->player_dir_x != 0 || data->player_dir_y != 0)
	{
		printf("Error\nDuplicate start position\n");
		return (1);
	}
	set_vector_dir_plane(data, direction);
	data->player_x = x;
	data->player_y = y;
	return (0);
}

int	initialize_player(t_data *data)
{
	int	i;
	int	j;
	int	ret;

	i = -1;
	ret = 0;
	while (++i < data->map_height)
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N')
				ret = set_player_dir(data, 'N', j, i);
			else if (data->map[i][j] == 'S')
				ret = set_player_dir(data, 'S', j, i);
			else if (data->map[i][j] == 'W')
				ret = set_player_dir(data, 'W', j, i);
			else if (data->map[i][j] == 'E')
				ret = set_player_dir(data, 'E', j, i);
			if (ret == 1)
				return (1);
			j++;
		}
	}
	return (0);
}
