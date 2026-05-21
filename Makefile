NAME = cub3D

CC = cc
# Ajout de -g pour le debug si besoin, et correction des includes
CFLAGS = -Wall -Wextra -Werror -I includes -I libft -I libft/get_next_line -I mlx
MLX = mlx/libmlx_Linux.a
# -lm doit souvent être à la fin de la ligne de compilation
MLXFLAGS = -L/usr/lib -lXext -lX11 -lm

RM = rm -rf
LIBFT = libft/libft.a

SRC =	srcs/main/main.c \
		srcs/parsing/map.c \
		srcs/parsing/parse_color.c \
		srcs/parsing/parse_direction.c \
		srcs/parsing/parsing.c \
		srcs/parsing/process_line.c \
		srcs/parsing/read_file.c \
		srcs/player/initialize_player.c \
		srcs/player/move_player.c \
		srcs/player/draw_player.c \
		srcs/render/render_frame.c \
		srcs/utils/parsing_utils.c \
		srcs/utils/parsing_utils_2.c \
		srcs/utils/utils.c \
		srcs/utils/window_utils.c \
		srcs/window/windowstart.c \
		srcs/window/handling.c \
		srcs/window/draw_background.c \
		srcs/window/game_loop.c \
		srcs/window/draw_map.c \
		srcs/cleanup/cleanup.c \
		srcs/raycast/raycast.c \

OBJ_DIR = objs
OBJS = $(SRC:srcs/%.c=$(OBJ_DIR)/%.o)

LIBFT = libft/libft.a

# Couleurs
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
BLUE = \033[0;34m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@echo "$(BLUE)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -Llibft -lft $(MLX) $(MLXFLAGS) -o $(NAME)
	@echo "$(GREEN)✔ $(NAME) compiled successfully!$(RESET)"

# Compilation de la Libft
$(LIBFT):
	@echo "$(BLUE)Compiling libft...$(RESET)"
	@$(MAKE) -C libft

# Règle générique pour les objets avec création de sous-dossiers
$(OBJ_DIR)/%.o: srcs/%.c
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@$(RM) $(OBJ_DIR)
	@$(MAKE) -C libft clean

fclean: clean
	@echo "$(RED)Removing executable...$(RESET)"
	@$(RM) $(NAME)
	@$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re

.SILENT:
