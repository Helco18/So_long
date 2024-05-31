# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcannaud <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/11 18:14:18 by gcannaud          #+#    #+#              #
#    Updated: 2023/11/20 17:01:30 by gcannaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -I ./libft/include/ -I ./includes/ -I ./mlx
NAME = so_long
MY_SOURCES = move.c move1234.c main.c so_long.c load.c close.c enemy.c mapisvalid.c enemy1.c attack.c attack2.c
MY_OBJECTS = $(MY_SOURCES:.c=.o)



all : libft $(NAME)

libft :
	@make -C ./libft
	@make -C ./mlx

$(NAME) : $(MY_OBJECTS)
	cc -o $(NAME) $(MY_OBJECTS) $(CFLAGS) ./libft/libft.a -L ./mlx -lmlx -lXext -lX11 -lm -lbsd

clean :
	rm -rf $(MY_OBJECTS)
	cd ./libft && make clean
	cd ./mlx && make clean

fclean : clean
	rm -rf $(NAME)
	cd ./libft && rm -rf libft.a
	cd ./mlx && rm -rf libmlx.a
	cd ./mlx && rm -rf libmlx_Linux.a

re : fclean all

bonus : libft $(NAME)

.PHONY: all libft clean fclean re bonus
