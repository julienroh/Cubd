/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windowstart.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haoky <haoky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 12:00:39 by mfumeaux          #+#    #+#             */
/*   Updated: 2026/05/09 13:58:03 by haoky            ###   ########.fr       */
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
	render_frame(data);
	mlx_hook(data->mlx.win, KeyPress, KeyPressMask,
	handle_key_press, data);
	mlx_hook(data->mlx.win, KeyRelease, KeyReleaseMask,
	handle_key_release, data);
	mlx_loop_hook(data->mlx.mlx, game_loop, data);
	mlx_hook(data->mlx.win, DestroyNotify, StructureNotifyMask,
		&handle_close, data);
	mlx_loop(data->mlx.mlx);
	clean(data);
}
