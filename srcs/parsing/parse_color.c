/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haoky <haoky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 20:32:07 by haoky             #+#    #+#             */
/*   Updated: 2026/04/28 11:32:16 by haoky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	set_color(t_data *data, t_color *color, char type)
{
	if (type == 'F')
	{
		if (data->floor.is_set)
			return (data->error_msg = "Duplicate floor color", PARSE_ERROR);
		data->floor = *color;
		data->floor.is_set = 1;
	}
	else
	{
		if (data->ceiling.is_set)
			return (data->error_msg = "Duplicate floor color", PARSE_ERROR);
		data->ceiling = *color;
		data->ceiling.is_set = 1;
	}
	return (PARSE_OK);
}

static int	parse_rgb(char *line, t_color *color, t_data *data)
{
	char	**rgb;

	rgb = ft_split(line, ',');
	if (!rgb)
		return (data->error_msg = "Malloc failed", PARSE_ERROR);
	if (!is_nbr(rgb[0]) || !is_nbr(rgb[1]) || !is_nbr(rgb[2]) || rgb[3])
	{
		free_tab(rgb);
		return (data->error_msg = "Invalid color format", PARSE_ERROR);
	}
	color->r = ft_atoi(skip_spaces(rgb[0]));
	color->g = ft_atoi(skip_spaces(rgb[1]));
	color->b = ft_atoi(skip_spaces(rgb[2]));
	if (color->r < 0 || color->r > 255
		|| color->g < 0 || color->g > 255
		|| color->b < 0 || color->b > 255)
	{
		free_tab(rgb);
		return (data->error_msg = "Color out of range", PARSE_ERROR);
	}
	free_tab(rgb);
	return(PARSE_OK);
}

int	read_color(t_data *data, char *line)
{
	char	type;
	t_color	tmp;

	line = skip_spaces(line);
	if (*line != 'F' && *line != 'C')
		return (PARSE_NOT_MATCH);
	type = *line++;
	line = skip_spaces(line);
	if (parse_rgb(line, &tmp, data) == PARSE_ERROR)
		return (PARSE_ERROR);
	return (set_color(data, &tmp, type));
}
