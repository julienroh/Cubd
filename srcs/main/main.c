/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroh <jroh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 09:43:24 by jroh              #+#    #+#             */
/*   Updated: 2026/04/23 11:54:57 by jroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	initialize_data(t_data *data)
{
	data->no = NULL;
	data->so = NULL;
	data->we = NULL;
	data->ea = NULL;
	data->floor.is_set = 0;
	data->ceiling.is_set = 0;
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		printf("Usage: ./cub3D map.cub\n");
		return (1);
	}
	(void)argc;
	(void)argv;
	initialize_data(&data);
	if (parsing_file(&data, argv[1]) == 1)
		return (1);
	return (0);
}