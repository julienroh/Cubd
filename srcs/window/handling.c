/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfumeaux <mfumeaux@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 12:00:37 by mfumeaux          #+#    #+#             */
/*   Updated: 2026/05/06 12:00:38 by mfumeaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	handle_input(int keysym, t_data *data)
{
	int	i;

	i = 0;
	if (keysym == XK_Escape)
	{
		i = mlx_loop_end(data->mlx.mlx);
		if (i != 0)
			return i;
	}
	return (0);
}

int	handle_close(t_data *data)
{
	int	i;

	i = 0;
	i = mlx_loop_end(data->mlx.mlx);
	if (i != 0)
		return i;
	return (0);
}
