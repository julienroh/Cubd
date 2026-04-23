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

# define WIN_H 1920
# define WIN_W 3000

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
	char	*ea;

	t_color	floor;
	t_color	ceiling;

	char	**map;

	int		map_width;
	int		map_height;

	int		player_x;
	int		player_y;
	char	*player_dir;

	t_mlx mlx;
}	t_data;

void	clean(t_data *data);
void	start(t_data *data);
void	img_pix_put(t_mlx *mlx, int x, int y, int color);
int		handle_input(int keysym, t_data *data);
int		handle_close(t_data *data);

#endif