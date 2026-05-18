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


# define TILE_SIZE 32
# define WIN_H 1024
# define WIN_W 720
# define PARSE_OK 0
# define PARSE_ERROR 1
# define PARSE_NOT_MATCH 2
//# define M_PI 3.141592654

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

	int		key_w;
	int		key_s;
	int		key_a;
	int		key_d;

	t_color	floor;//a free
	t_color	ceiling;//a free

	char	**map;//a free

	int		map_width;
	int		map_height;

	double	player_x;
	double	player_y;
	double	player_dir_x;
	double	player_dir_y;
	double	plane_x;
	double	plane_y;
	double	dir_x;
	double	dir_y;
	double	screen_ratio;
	double	raydir_x;
	double	raydir_y;
	double	map_x;
	double	map_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	stepx;
	double	stepy;
	double	perp_wall_dist;
	double	side;
	double	hit;

	char	*error_msg;
	t_mlx	mlx;
}	t_data;


//camera.c


//raycast.c


//cleanup.c

void	clean(t_data *data);

//windowstart.c

void	start(t_data *data);

//draw_background.c

void	draw_background(t_data *data);

//handling.c

int		handle_key_press(int keysym, t_data *data);
int		handle_key_release(int keysym, t_data *data);
int		handle_close(t_data *data);

//draw_map.c

void	draw_map(t_data *data);

//game_loop.c

int		game_loop(t_data *data);

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

//draw_player.c

void	draw_player(t_data *data);

//initialize_player.c

int		initialize_player(t_data *data);

//move_player.c

void	move_forward(t_data *data);
void	move_backward(t_data *data);
void	rotate_left(t_data *data);
void	rotate_right(t_data *data);

//render_frame.c

void	render_frame(t_data *data);

//parsing_utils_2.c

int		is_nbr(char *s);

//utils.c

int		ft_isspace(char c);
void	initialize_data_two(t_data *data);

//window_utils.c

int		rgb_to_int(t_color color);
void	img_pix_put(t_mlx *mlx, int x, int y, int color);
void	draw_square(t_data *data, int start_x, int start_y, int color);

#endif
