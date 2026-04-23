#ifndef CUB3D_H
# define CUB3D_H

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>


typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	is_set;
}	t_color;

typedef struct s_data
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;

	t_color	floor;
	t_color	ceiling;

	char	**map;

	int		map_width;
	int		map_height;

	int		player_x;
	int		player_y;
	char	*player_dir;

}	t_data;

//parsing

int		parsing_file(t_data *data, char *file);
void	read_file(t_data *data, int fd);

//utils

int		ft_isspace(char c);

#endif