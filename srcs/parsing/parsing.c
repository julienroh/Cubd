/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haoky <haoky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 10:10:50 by jroh              #+#    #+#             */
/*   Updated: 2026/04/23 20:29:54 by haoky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
	return (0);
}
