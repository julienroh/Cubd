NAME = cub3d

CC = cc
CFLAGS = -Wall -Wextra -Werror -I includes -I libft -I libft/get_next_line

RM = rm -rf

SRC = srcs/main.c

OBJ_DIR = objs
OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
BLUE = \033[0;34m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(BLUE)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✔ $(NAME) compiled successfully!$(RESET)"

$(OBJ_DIR)/%.o: srcs/%.c
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@$(RM) $(OBJ_DIR)

fclean: clean
	@echo "$(RED)Removing executable...$(RESET)"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

.SILENT: