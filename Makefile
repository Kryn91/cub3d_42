NAME    := cub3d
CC      := cc
CFLAGS  := -Wall -Wextra -Werror -MMD

# Folder
SRC_DIR := Src
OBJ_DIR := .obj
INC_DIR := Includes
LIB_DIR := Lib
LIBFT_DIR := $(LIB_DIR)/libft
MLX_DIR := $(LIB_DIR)/Mlx

# MLX
MLX_URL := https://github.com/42paris/minilibx-linux.git
# ============================================================
#  Src Files
# ============================================================

SRCS := main.c
LIBFT := $(LIBFT_DIR)/libft.a
# ============================================================
#  Generate complete Path
# ============================================================

OBJS    := $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
IFLAGS  := -I$(INC_DIR) -I$(LIB_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)

# ============================================================
#  Rules
# ============================================================
all: libs mlx $(NAME)

mlx :
	git clone $(MLX_URL) $(MLX_DIR)
	$(MAKE) -C $(MLX_DIR)

libs:
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(MLX_FLAG) $(OBJS) $(LIBFT) -L$(MLX_DIR) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -rf $(MLX_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)
	

-include $(OBJS:.o=.d)

re: fclean all

.PHONY: all clean fclean re libs
