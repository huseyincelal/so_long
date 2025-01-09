# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hugozlu <hugozlu@student.42istanbul.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/01 19:23:41 by hugozlu           #+#    #+#              #
#    Updated: 2025/01/02 13:17:27 by hugozlu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -Lminilibx-linux -Llibs/ft_printf
LDLIBS =libs/ft_printf/libftprintf.a -lmlx -lX11 -lXext
SRCS = libs/get_next_line/get_next_line.c libs/get_next_line/get_next_line_utils.c move.c map_check.c \
	image_to_window.c map_malloc.c import_assets.c so_long_utils.c libs/ft_itoa.c libs/ft_strdup.c main.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):libs/ft_printf/libftprintf.a $(OBJS) minilibx-linux/libmlx.a
	$(CC)  $(OBJS) -o $(NAME) $(LDFLAGS) $(LDLIBS)

libs/ft_printf/libftprintf.a:
	$(MAKE) -C libs/ft_printf

minilibx-linux/libmlx.a:
	$(MAKE) -C minilibx-linux

clean:
	rm -f $(OBJS)
	$(MAKE) -C libs/ft_printf clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libs/ft_printf fclean

re: fclean all
