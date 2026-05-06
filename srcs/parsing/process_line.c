/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haoky <haoky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 20:19:46 by haoky             #+#    #+#             */
/*   Updated: 2026/04/28 11:18:15 by haoky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	handle_map_line(t_data *data, char *line)
{
	if (!is_map_line(line))
		return (printf("Error\nInvalid map\n"), 1);
	return (add_map_line(data, line));
}

static int	handle_config_line(t_data *data, char *line, int *in_map)
{
	int	ret;

	ret = read_direction(data, line);
	if (ret == PARSE_ERROR)
		return (error_exit(data));
	if (ret == PARSE_NOT_MATCH)
	{
		ret = read_color(data, line);
		if (ret == PARSE_ERROR)
			return (error_exit(data));
		if (ret == PARSE_NOT_MATCH)
		{
			if (!is_map_line(line))
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
		return (handle_map_line(data, line));
	return (handle_config_line(data, tmp, in_map));
}
