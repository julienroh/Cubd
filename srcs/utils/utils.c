/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroh <jroh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 13:28:16 by jroh              #+#    #+#             */
/*   Updated: 2026/05/29 15:26:48 by jroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

void	initialize_data_two(t_data *data)
{
	data->screen_ratio = 0;
	data->raydir_x = 0;
	data->raydir_y = 0;
	data->map_x = 0;
	data->map_y = 0;
	data->sidedist_x = 0;
	data->sidedist_y = 0;
	data->deltadist_x = 0;
	data->deltadist_y = 0;
	data->error_msg = NULL;
	data->mlx.img = NULL;
	data->mlx.mlx = NULL;
	data->mlx.addr = NULL;
}
