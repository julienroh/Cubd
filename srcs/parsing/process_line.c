/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfumeaux <mfumeaux@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 20:19:46 by haoky             #+#    #+#             */
/*   Updated: 2026/06/08 11:34:15 by mfumeaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	handle_map_line(t_data *data, char *line)
{
	if (!is_map_line(line))
		return (printf("Error\nInvalid map position\n"), 1);
	return (add_map_line(data, line));
}

static int	handle_config_line(t_data *data, char *tmp, char *line, int *in_map)
{
	int	ret;

	ret = read_direction(data, tmp);
	if (ret == PARSE_ERROR)
		return (error_exit(data));
	if (ret == PARSE_NOT_MATCH)
	{
		ret = read_color(data, tmp);
		if (ret == PARSE_ERROR)
			return (error_exit(data));
		if (ret == PARSE_NOT_MATCH)
		{
			if (!is_map_line(tmp))
				return (printf("Error\nInvalid line\n"), 1);
			*in_map = 1;
			return (add_map_line(data, line));
		}
	}
	return (0);
}

int	process_line(t_data *data, char *line, int *in_map)
{
	char	*tmp;

	if (!*in_map)
		tmp = skip_spaces(line);
	else
		tmp = line;
	if (*tmp == '\0' || *tmp == '\n')
		return (0);
	if (*in_map)
	{
		tmp = line;
		return (handle_map_line(data, line));
	}
	return (handle_config_line(data, tmp, line, in_map));
}
