NAME    := cub3d
CC      := cc
CFLAGS  := -Wall -Wextra -Werror 
# Folder
SRC_DIR := src
OBJ_DIR := .obj
INC_DIR := includes
LIB_DIR := libft

# ============================================================
#  Src Files
# ============================================================

SRCS    := main.c

# ============================================================
#  Generate complete Path
# ============================================================

OBJS    := $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
IFLAGS  := -I$(INC_DIR) -I$(LIB_DIR)/include

# ============================================================
#  Rules
# ============================================================

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all