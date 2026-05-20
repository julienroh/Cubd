/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haoky <haoky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 18:53:52 by haoky             #+#    #+#             */
/*   Updated: 2026/05/20 14:08:04 by haoky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	all_set(t_data *data)
{
	if (data->no != NULL && data->so != NULL
		&& data->we != NULL && data->ea != NULL
		&& data->floor.is_set == 1 && data->ceiling.is_set == 1)
		return (0);
	else
		return (1);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	*skip_spaces(char *str)
{
	while (ft_isspace(*str))
		str++;
	return (str);
}

int	error_exit(t_data *data)
{
	printf("Error\n");
	if (data->error_msg)
		printf("%s\n", data->error_msg);
	return (1);
}
