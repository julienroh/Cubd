/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haoky <haoky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 12:28:48 by jroh              #+#    #+#             */
/*   Updated: 2026/05/20 14:05:40 by haoky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	read_file(t_data *data, int fd)
{
	char	*line;
	int		in_map;

	in_map = 0;
	while ((line = get_next_line(fd)))
	{
		if (process_line(data, line, &in_map) == 1)
			return (free(line), 1);
		free(line);
	}
	if (!data->map)
		return (printf("Error\nNo map\n"), 1);
	if (all_set(data) != 0)
		return (printf("Error\nMissing elements\n"), 1);
	return (0);
}
