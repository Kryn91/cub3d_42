# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kealves- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/13 15:14:42 by kealves-          #+#    #+#              #
#    Updated: 2025/11/21 12:51:32 by kealves-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS= -Wall -Wextra -Werror
SRC = ft_atoi.c ft_isdigit.c ft_memmove.c ft_strlen.c ft_toupper.c ft_bzero.c \
      	ft_isprint.c ft_memset.c ft_strncmp.c ft_isalnum.c ft_memchr.c ft_strchr.c \
      	ft_strnstr.c ft_isalpha.c ft_memcmp.c ft_strlcat.c ft_strrchr.c ft_isascii.c \
      	ft_memcpy.c ft_strlcpy.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c \
	ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
       	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstadd_front.c \
	ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
	ft_lstiter.c ft_lstmap.c 
SRCBONUS = ft_lstnew.c
HEADER = libft.h
NAME=libft.a
OBJ= $(SRC:.c=.o)
OBJBONUS= $(SRCBONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $@ $(OBJ)

%.o	: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $<  -o $@

bonus:	$(OBJ) $(OBJBONUS) $(HEADER)
	ar -rcs $(NAME) $(OBJ) $(OBJBONUS)
clean:
	rm -f $(OBJ) $(OBJBONUS)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY	: all clean fclean re bonus
