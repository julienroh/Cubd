/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfumeaux <mfumeaux@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 12:00:30 by mfumeaux          #+#    #+#             */
/*   Updated: 2026/06/07 13:16:05 by mfumeaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	clean_tex_images(t_data *data)
{
	if (data->tex_east.img_ptr)
	{
		mlx_destroy_image(data->mlx.mlx, data->tex_east.img_ptr);
		data->tex_east.img_ptr = NULL;
	}
	if (data->tex_north.img_ptr)
	{
		mlx_destroy_image(data->mlx.mlx, data->tex_north.img_ptr);
		data->tex_north.img_ptr = NULL;
	}
	if (data->tex_west.img_ptr)
	{
		mlx_destroy_image(data->mlx.mlx, data->tex_west.img_ptr);
		data->tex_west.img_ptr = NULL;
	}
	if (data->tex_south.img_ptr)
	{
		mlx_destroy_image(data->mlx.mlx, data->tex_south.img_ptr);
		data->tex_south.img_ptr = NULL;
	}
}

void	clean(t_data *data)
{
	clean_tex_images(data);
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
}
