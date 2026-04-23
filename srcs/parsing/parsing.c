/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroh <jroh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 10:10:50 by jroh              #+#    #+#             */
/*   Updated: 2026/04/23 12:29:08 by jroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	parsing_file(t_data *data, char *file)
{
	int		fd;
	
	(void)data;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	read_file(data, fd);
	return (0);
}