/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroh <jroh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 14:32:01 by jroh              #+#    #+#             */
/*   Updated: 2026/06/02 13:00:03 by jroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// static void	free_color(t_color color)
// {
// 	free(color.r);
// 	free(color.g);
// 	free(color.b);
// }

static void	free_path(t_data *data)
{
	free(data->no);
	free(data->so);
	free(data->we);
	free(data->ea);
}

void	free_all(t_data *data)
{
	free_map(data->map);
	// free_color(data->floor);
	// free_color(data->ceiling);
	free_path(data);
}
