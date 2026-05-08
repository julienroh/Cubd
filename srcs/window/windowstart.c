/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windowstart.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haoky <haoky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 12:00:39 by mfumeaux          #+#    #+#             */
/*   Updated: 2026/05/08 12:11:07 by haoky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	start(t_data *data)
{
	data->mlx.mlx = mlx_init();
	if (!data->mlx.mlx)
		return ;
	data->mlx.win = mlx_new_window(data->mlx.mlx, WIN_W, WIN_H, "LoupCaillou");
	if (!data->mlx.win)
		return ;
	data->mlx.img = mlx_new_image(data->mlx.mlx, WIN_W, WIN_H);
	if (!data->mlx.img)
		return ;
	data->mlx.addr = mlx_get_data_addr(data->mlx.img, &data->mlx.bits_per_pixel,
			&data->mlx.line_len, &data->mlx.endian);
	draw_background(data);
	draw_map(data);
	//draw_player(data);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img, 0, 0);
	mlx_key_hook(data->mlx.win, &handle_input, data);
	mlx_hook(data->mlx.win, DestroyNotify, StructureNotifyMask,
		&handle_close, data);
	mlx_loop(data->mlx.mlx);
	clean(data);
}
