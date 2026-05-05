/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haoky <haoky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 20:23:35 by haoky             #+#    #+#             */
/*   Updated: 2026/04/28 11:24:08 by haoky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_map_width(char **map)
{
	int	max;
	int	len;
	int	i;

	max = 0;
	i = 0;

	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len > max)
			max = len;
		i++;
	}
	return (max);
}

int	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '0' && line[i] != '1'
			&& line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'E' && line[i] != 'W'
			&& line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	add_map_line(t_data *data, char *line)
{
	char	**new_map;
	int		i;

	new_map = malloc(sizeof(char *) * (data->map_height + 2));
	if (!new_map)
		return (data->error_msg = "Malloc failed", PARSE_ERROR);

	i = 0;
	while (i < data->map_height)
	{
		new_map[i] = ft_strdup(data->map[i]);
		if (!new_map[i])
			return (free_map(new_map),
				data->error_msg = "Malloc failed", PARSE_ERROR);
		i++;
	}
	new_map[i] = ft_strtrim(line, "\n");
	if (!new_map[i])
		return (free_map(new_map),
				data->error_msg = "Malloc failed", PARSE_ERROR);
	new_map[i + 1] = NULL;
	free_map(data->map);
	data->map = new_map;
	data->map_height++;
	return (PARSE_OK);
}
