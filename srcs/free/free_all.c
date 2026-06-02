/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfumeaux <mfumeaux@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 14:32:01 by jroh              #+#    #+#             */
/*   Updated: 2026/06/02 14:03:40 by mfumeaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
	free_path(data);
}
