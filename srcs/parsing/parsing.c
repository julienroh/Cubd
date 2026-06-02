/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroh <jroh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 10:10:50 by jroh              #+#    #+#             */
/*   Updated: 2026/06/02 12:57:39 by jroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	is_element(char c)
{
	if (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

static int	is_surrounded(char **map, int i, int j)
{
	if (i == 0 || j == 0)
		return (0);
	if (!is_element(map[i - 1][j]) || !is_element(map[i + 1][j])
		|| !is_element(map[i][j - 1]) || !is_element(map[i][j + 1]))
		return (0);
	return (1);
}

static int	check_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != ' ' &&
				is_surrounded(map, i, j) == 0)
			{
				printf("Error\nMap not surrounded by walls\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	parsing_file(t_data *data, char *file)
{
	int		fd;

	(void)data;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (printf("Error\nCannot open file\n"), 1);
	if (read_file(data, fd) == 1)
		return (close(fd), 1);
	close(fd);
	if (check_map(data->map) == 1)
		return (1);
	return (0);
}
