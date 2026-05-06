/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfumeaux <mfumeaux@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 09:43:24 by jroh              #+#    #+#             */
/*   Updated: 2026/05/06 12:03:51 by mfumeaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}

static void	print_color(t_color color)
{
	printf("r = %d\n", color.r);
	printf("g = %d\n", color.g);
	printf("b = %d\n", color.b);
	printf("is_set = %d\n", color.is_set);
}

static void	print_data(t_data *data)
{
	printf("NO = %s\n", data->no);
	printf("SO = %s\n", data->so);
	printf("WE = %s\n", data->we);
	printf("EA = %s\n", data->ea);

	printf("floor : \n");
	print_color(data->floor);
	printf("ceiling : \n");
	print_color(data->ceiling);

	print_map(data->map);
	printf("map width = %d\n", data->map_width);
	printf("map height = %d\n", data->map_height);

	printf("player_x = %d\n", data->player_x);
	printf("player_y = %d\n", data->player_y);
	printf("player_dir = %c\n", data->player_dir);
	printf("error_msg = %s\n", data->error_msg);
}

static void	initialize_data(t_data *data)
{
	data->no = NULL;
	data->so = NULL;
	data->we = NULL;
	data->ea = NULL;
	data->floor.is_set = 0;
	data->ceiling.is_set = 0;
	data->map = NULL;
	data->map_height = 0;
	data->map_width = 0;
	data->player_x = 0;
	data->player_y = 0;
	data->player_dir = '\0';
	data->error_msg = NULL;
	data->mlx.img = NULL;
	data->mlx.mlx = NULL;
	data->mlx.addr = NULL;
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
		return (1); //free_all(data);
	data.map_width = get_map_width(data.map);
	if (initialize_player(&data) == 1)
		return (1);//free_all(data);
	print_data(&data);
	start(&data);
	clean(&data);
	return (0);
}
