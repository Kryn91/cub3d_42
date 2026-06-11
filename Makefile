NAME    := cub3d
CC      := cc
CFLAGS  := -Wall -Wextra -Werror -MMD -g3
MLX_FLAG := -lmlx -lXext -lX11 -lm

# Folder
SRC_DIR := Src
OBJ_DIR := .obj
INC_DIR := Includes
LIB_DIR := Lib
LIBFT_DIR := $(LIB_DIR)/libft
MLX_DIR := $(LIB_DIR)/Mlx
GNL_DIR := $(LIB_DIR)/Gnl
INC_PARSING := $(INC_DIR)/Parsing
INC_MOVEMENT := $(INC_DIR)/Movement

# MLX
MLX_URL := https://github.com/42paris/minilibx-linux.git
MLX_BRANCH := fedora

# ============================================================
#  Src Files
# ============================================================

SRCS :=	main.c						\
		Parsing/parsing.c			\
		Parsing/read_map_file.c		\
		Parsing/texture_parser.c	\
		Parsing/texture_parsing.c	\
		Parsing/color_parser.c		\
		Rendering/test.c			\
		Rendering/render.c			\
		Rendering/minimap.c			\
		Rendering/mlx_render.c		\
		Utils/free_memory.c			\
		Movement/handle_input.c		\
		Movement/movement.c

LIBFT := $(LIBFT_DIR)/libft.a

GNL :=	$(GNL_DIR)/get_next_line.c		\
		$(GNL_DIR)/get_next_line_utils.c


# ============================================================
#  Generate complete Path
# ============================================================

OBJS    := $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
IFLAGS  := -I$(INC_DIR) -I$(LIB_DIR) -I$(LIBFT_DIR) -I$(INC_PARSING) -I$(INC_MOVEMENT) -I$(GNL_DIR) -I$(MLX_DIR)

# ============================================================
#  Rules
# ============================================================

all: libs mlx $(NAME)

mlx :
	@if [ ! -d "$(MLX_DIR)/.git" ]; then \
		git clone --branch $(MLX_BRANCH) $(MLX_URL) $(MLX_DIR); \
		$(MAKE) -C $(MLX_DIR); \
	fi

libs:
	$(MAKE) -C $(LIBFT_DIR) -j

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(GNL) -L$(MLX_DIR) $(MLX_FLAG) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) clean -C $(LIBFT_DIR) -j
	rm -rf $(MLX_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

-include $(OBJS:.o=.d)

re: fclean all

.PHONY: all clean fclean re libs
