#ifndef CUB3D_H
# define CUB3D_H

#include "libft.h"
#include "mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdbool.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include <math.h>

# define WIN_H 500
# define WIN_W 500
# define PARSE_OK 0
# define PARSE_ERROR 1
# define PARSE_NOT_MATCH 2

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	is_set;
}	t_color;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
	int		offset;

}	t_mlx;

typedef struct s_data
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;//a free

	t_color	floor;//a free
	t_color	ceiling;//a free

	char	**map;//a free

	int		map_width;
	int		map_height;

	int		player_x;
	int		player_y;
	char	player_dir;

	char	*error_msg;
	t_mlx	mlx;
}	t_data;


//window handling

void	clean(t_data *data);
void	start(t_data *data);
int		handle_input(int keysym, t_data *data);
int		handle_close(t_data *data);

//map.c

int		get_map_width(char **map);
int		is_map_line(char *line);
int		add_map_line(t_data *data, char *line);

//parse_color.c

int		read_color(t_data *data, char *line);

//parse_direction.c

int		read_direction(t_data *data, char *line);

//parsing.c

int		parsing_file(t_data *data, char *file);

//process_line.c

int		process_line(t_data *data, char *line, int *in_map);

//read_file.c

int		read_file(t_data *data, int fd);

//parsing_utils.c

int		all_set(t_data *data);
void	free_map(char **map);
void	free_tab(char **tab);
char	*skip_spaces(char *str);
int		error_exit(t_data *data);

//initialize_player.c

int		initialize_player(t_data *data);

//parsing_utils_2.c

int		is_nbr(char *s);

//utils.c

int		ft_isspace(char c);

#endif
