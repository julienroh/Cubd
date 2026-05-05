/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haoky <haoky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 15:47:38 by haoky             #+#    #+#             */
/*   Updated: 2026/04/28 16:05:34 by haoky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	set_player_dir(t_data *data, char direction, int x, int y)
{
	if (data->player_dir != '\0')
	{
		printf("Error\nDuplicate start position\n");
		return (1);
	}
	data->player_dir = direction;
	data->player_x = x;
	data->player_y = y;
	return (0);
}

int	initialize_player(t_data *data)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N')
				ret = set_player_dir(data, 'N', j, i);
			else if (data->map[i][j] == 'S')
				ret = set_player_dir(data, 'S', j, i);
			else if (data->map[i][j] == 'S')
				ret = set_player_dir(data, 'S', j, i);
			else if (data->map[i][j] == 'S')
				ret = set_player_dir(data, 'S', j, i);
			if (ret == 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
