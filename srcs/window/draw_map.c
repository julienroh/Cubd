/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroh <jroh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:31:32 by haoky             #+#    #+#             */
/*   Updated: 2026/05/29 13:22:08 by jroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '0')
				draw_square(data, j * MMAP_SIZE, i * MMAP_SIZE, 0x000000);
			else if (data->map[i][j] == '1')
				draw_square(data, j * MMAP_SIZE, i * MMAP_SIZE, 0xFFFFFF);
			j++;
		}
		i++;
	}
}
