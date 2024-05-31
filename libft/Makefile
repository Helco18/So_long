# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcannaud <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/11 18:14:18 by gcannaud          #+#    #+#              #
#    Updated: 2023/12/20 16:50:23 by gcannaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
HEAD = include
CFLAGS = -Wall -Wextra -Werror -I ${HEAD}
NAME = libft.a

SRC = src/
GNL = gnl/
PRF = printf/
LST = lst/

SOURCES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
			ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
			ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
			ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
			ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_lenint.c \
			$(LST)ft_lstnew.c $(LST)ft_lstadd_front.c $(LST)ft_lstsize.c $(LST)ft_lstlast.c $(LST)ft_lstadd_back.c \
			$(LST)ft_lstdelone.c $(LST)ft_lstclear.c $(LST)ft_lstiter.c $(LST)ft_lstmap.c \
			$(PRF)ft_printf.c $(PRF)ft_function.c $(PRF)ft_hexa_function.c $(PRF)ft_is.c $(PRF)ft_hexa_is.c \
			$(GNL)ft_strdeljoin.c $(GNL)get_next_line.c

MY_SOURCES = $(addprefix $(SRC), $(SOURCES))

MY_OBJECTS = $(MY_SOURCES:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME) : $(MY_OBJECTS)
	ar rcs $(NAME) $(MY_OBJECTS)

clean :
	rm -rf $(MY_OBJECTS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
