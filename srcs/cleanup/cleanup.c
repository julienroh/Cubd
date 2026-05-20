/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haoky <haoky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 12:00:30 by mfumeaux          #+#    #+#             */
/*   Updated: 2026/05/20 14:04:19 by haoky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	clean(t_data *data)
{
	if (data->mlx.img)
	{
		mlx_destroy_image(data->mlx.mlx, data->mlx.img);
		data->mlx.img = NULL;
	}
	if (data->mlx.win)
	{
		mlx_destroy_window(data->mlx.mlx, data->mlx.win);
		data->mlx.win = NULL;
	}
	if (data->mlx.mlx)
	{
		mlx_destroy_display(data->mlx.mlx);
		free(data->mlx.mlx);
		data->mlx.mlx = NULL;
	}
	// Insérer les free du parsing ici.
}
