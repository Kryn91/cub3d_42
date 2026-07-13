NAME    := cub3d
CC      := cc
CFLAGS  := -Wall -Wextra -Werror -g3 -g -O0
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
INC_CHECKER := $(INC_DIR)/Checker
INC_GAME := $(INC_DIR)/Game
INC_RENDER := $(INC_DIR)/Rendering
INC_UTILS := $(INC_DIR)/Utils

# MLX
MLX_URL := https://github.com/42paris/minilibx-linux.git
MLX_BRANCH := fedora

# ============================================================
#  Src Files
# ============================================================

SRCS :=	main.c							\
		Parsing/parsing.c				\
		Parsing/read_map_file.c			\
		Parsing/texture_parser.c		\
		Parsing/texture_parsing.c		\
		Parsing/color_parser.c			\
		Parsing/init_player.c			\
		Parsing/init_door.c 			\
		Parsing/init_enemy.c			\
		Parsing/init_texture.c			\
		Checker/checker.c 				\
		Checker/map_checker.c			\
		Checker/map_solver.c			\
		Checker/solver.c				\
		Rendering/render.c				\
		Rendering/minimap.c				\
		Rendering/mlx_render.c			\
		Rendering/raycasting.c			\
		Rendering/raycasting2.c			\
		Rendering/render_entity.c		\
		Utils/free_memory.c				\
		Utils/free_list.c				\
		Utils/vector_manipulation.c		\
		Utils/delta_time.c 				\
		Movement/handle_input.c			\
		Movement/movement.c				\
		Movement/interact.c				\
		Movement/colision.c 			\
		Game/game_loop.c				\
		Game/door.c						\
		Game/attack.c					\
		Game/enemy_patrol.c				\
		Game/enemy_colision.c			\
		Game/enemy_choose_direction.c	\
		Game/enemy_detect_player.c		\
		Game/enemy_chase_player.c		\
		Game/enemy_attack_player.c

LIBFT := $(LIBFT_DIR)/libft.a

GNL :=	$(GNL_DIR)/get_next_line.c		\
		$(GNL_DIR)/get_next_line_utils.c


# ============================================================
#  Generate complete Path
# ============================================================

OBJS    := $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
IFLAGS  := -I$(INC_DIR) -I$(LIB_DIR) -I$(LIBFT_DIR) -I$(INC_PARSING) -I$(INC_CHECKER) -I$(INC_MOVEMENT) \
-I$(INC_UTILS) -I$(INC_GAME) -I$(INC_RENDER) -I$(GNL_DIR) -I$(MLX_DIR)

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
	$(MAKE) bonus -C $(LIBFT_DIR) -j

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(GNL) -L$(MLX_DIR) $(MLX_FLAG) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -MMD $(IFLAGS) -c $< -o $@

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
