/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroh <jroh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 09:43:24 by jroh              #+#    #+#             */
/*   Updated: 2026/04/23 10:54:46 by jroh             ###   ########.fr       */
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
}

int	main(int argc, char **argv)
{
	t_data	data;

	(void)argc;
	(void)argv;
	initialize_data(&data);
	if (!data.floor.is_set)
		printf("nul\n");
	// parsing_file(&data, argv[1]);
	return (0);
}