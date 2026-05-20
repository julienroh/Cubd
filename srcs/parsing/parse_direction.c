/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_direction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haoky <haoky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 20:30:58 by haoky             #+#    #+#             */
/*   Updated: 2026/05/20 14:05:15 by haoky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char	**get_texture_path(t_data *data, char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0 && ft_isspace(line[2]))
		return (&data->no);
	if (ft_strncmp(line, "SO ", 3) == 0 && ft_isspace(line[2]))
		return (&data->so);
	if (ft_strncmp(line, "WE ", 3) == 0 && ft_isspace(line[2]))
		return (&data->we);
	if (ft_strncmp(line, "EA ", 3) == 0 && ft_isspace(line[2]))
		return (&data->ea);
	return (NULL);
}

int	read_direction(t_data *data, char *line)
{
	char	**path;

	line = skip_spaces(line);
	path = get_texture_path(data, line);
	if (!path)
		return (PARSE_NOT_MATCH);
	if (*path)
		return (data->error_msg = "Duplicate texture", PARSE_ERROR);
	line += 2;
	line = skip_spaces(line);
	*path = ft_strtrim(line, " \n\t");
	if (!*path)
		return (data->error_msg = "Malloc failed", PARSE_ERROR);
	return (PARSE_OK);
}
