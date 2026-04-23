/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroh <jroh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 12:28:48 by jroh              #+#    #+#             */
/*   Updated: 2026/04/23 14:15:24 by jroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	all_set(t_data *data)
{
	if (data->no != NULL && data->so != NULL
		&& data->we != NULL && data->ea !=NULL
		&& data->floor.is_set == 1 && data->ceiling.is_set == 1)
		return (0);
	else
		return (1);
}

int	read_direction(t_data *data, char *line)
{
	char	**path;

	while (ft_isspace(*line))
		line++;
	if (ft_strncmp(line, "NO", 2) == 0 && ft_isspace(line[2]))
		path = &data->no;
	else if (ft_strncmp(line, "SO", 2) == 0 && ft_isspace(line[2]))
		path = &data->so;
	else if (ft_strncmp(line, "WE", 2) == 0 && ft_isspace(line[2]))
		path = &data->we;
	else if (ft_strncmp(line, "EA", 2) == 0 && ft_isspace(line[2]))
		path = &data->ea;
	else
		return (1);
	if (*path)
	{
		printf("Error : duplicat texture\n");
		return (1);
	}
	line += 2;
	while (ft_isspace(*line))
		line++;
	*path = ft_strtrim(line," \n\t");
	if (!*path)
	{
		printf("Error : malloc failed\n");
		return (1);
	}
	return (0);
}

int	read_color(t_data *data, char *line, char surface)
{
	char	*rgb;

	rgb = ft_split(line, ',');
	if ()
}

int	read_file(t_data *data, int fd)
{
	char	*line;
	int		i;
	int		to_return;

	while ((line = get_next_line(fd)))
	{
		i = 0;
		while (line[i])
		{
			if (line[i] == 'N' || line[i] == 'S'
				|| line[i] == 'W' || line[i] == 'E')
				to_return = read_direction(data, line, line[i]);
			else if (line[i] == 'F' || line[i] == 'C')
				to_return = read_color(data, line, line[i]);
			else
			{
				i++;
				continue;
			}
		}
		if (all_set(data) == 0)
			break ;
	}
}
