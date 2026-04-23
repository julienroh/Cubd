/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfumeaux <mfumeaux@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 09:43:24 by jroh              #+#    #+#             */
/*   Updated: 2026/04/23 13:13:03 by mfumeaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initialize_data(t_data *data)
{
	data->no = NULL;
	data->so = NULL;
	data->we = NULL;
	data->ea = NULL;
	data->floor.is_set = 0;
	data->ceiling.is_set = 0;
	data->mlx.img = NULL;
	data->mlx.mlx = NULL;
	data->mlx.addr = NULL;
}

int	main(int argc, char **argv)
{
	t_data	data;

	(void)argc;
	(void)argv;
	initialize_data(&data);
	//if (!data.floor.is_set)
		//printf("nul\n");
	// parsing_file(&data, argv[1]);
	start(&data);
	clean(&data);
	return (0);
}
