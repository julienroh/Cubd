NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror -I includes -I libft -I libft/get_next_line

RM = rm -rf

SRC = srcs/main/main.c \
      srcs/parsing/parsing.c \
	  srcs/parsing/read_file.c \
	  srcs/utils/utils.c \

OBJ_DIR = objs
OBJS = $(SRC:srcs/%.c=$(OBJ_DIR)/%.o)

LIBFT = libft/libft.a

GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
BLUE = \033[0;34m
RESET = \033[0m

all: $(NAME)

$(LIBFT):
	@echo "$(BLUE)Compiling libft...$(RESET)"
	@$(MAKE) -C libft

$(NAME): $(OBJS) $(LIBFT)
	@echo "$(BLUE)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -Llibft -lft -o $(NAME)
	@echo "$(GREEN)✔ $(NAME) compiled successfully!$(RESET)"

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