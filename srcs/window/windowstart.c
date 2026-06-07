/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windowstart.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfumeaux <mfumeaux@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 12:00:39 by mfumeaux          #+#    #+#             */
/*   Updated: 2026/06/07 13:17:27 by mfumeaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	initialize_data_textures_addresses(t_data *data)
{
	data->tex_north.data = mlx_get_data_addr(data->tex_north.img_ptr,
		&data->tex_north.bpp, &data->tex_north.line_len,
		&data->tex_north.endian);
	data->tex_south.data = mlx_get_data_addr(data->tex_south.img_ptr,
		&data->tex_south.bpp, &data->tex_south.line_len,
		&data->tex_south.endian);
	data->tex_east.data = mlx_get_data_addr(data->tex_east.img_ptr,
		&data->tex_east.bpp, &data->tex_east.line_len,
		&data->tex_east.endian);
	data->tex_west.data = mlx_get_data_addr(data->tex_west.img_ptr,
		&data->tex_west.bpp, &data->tex_west.line_len,
		&data->tex_west.endian);
}

static int	initialize_data_textures_images(t_data *data)
{
	data->tex_east.img_ptr = NULL;
	data->tex_south.img_ptr = NULL;
	data->tex_north.img_ptr = NULL;
	data->tex_west.img_ptr = NULL;
	data->tex_north.img_ptr = mlx_xpm_file_to_image(data->mlx.mlx, data->no, 
		&data->tex_north.width, &data->tex_north.height);
	data->tex_south.img_ptr = mlx_xpm_file_to_image(data->mlx.mlx, data->so, 
		&data->tex_south.width, &data->tex_south.height);
	data->tex_east.img_ptr = mlx_xpm_file_to_image(data->mlx.mlx, data->ea, 
		&data->tex_east.width, &data->tex_east.height);
	data->tex_west.img_ptr = mlx_xpm_file_to_image(data->mlx.mlx, data->we, 
		&data->tex_west.width, &data->tex_west.height);
	if (!data->tex_north.img_ptr || !data->tex_south.img_ptr
		|| !data->tex_east.img_ptr || !data->tex_west.img_ptr)
	{
		printf("Error\nFailed to load textures\n");
		free_all(data); //A TEST : CHECK LEAK SI LE LOAD DE TEXTURES FAIL ! ! 
		return (1);
	}
	initialize_data_textures_addresses(data);
	return (0);
}

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
	if (initialize_data_textures_images(data) == 1)
		return ;
	render_frame(data);
	mlx_hook(data->mlx.win, KeyPress, KeyPressMask,
		handle_key_press, data);
	mlx_hook(data->mlx.win, KeyRelease, KeyReleaseMask,
		handle_key_release, data);
	mlx_loop_hook(data->mlx.mlx, game_loop, data);
	mlx_hook(data->mlx.win, DestroyNotify, StructureNotifyMask,
		&handle_close, data);
	mlx_loop(data->mlx.mlx);
}
