# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vslutiak <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/23 18:45:58 by vslutiak          #+#    #+#              #
#    Updated: 2018/11/01 20:48:12 by vslutiak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = gcc -Wall -Wextra -Werror

INC = ./includes/libft.h

SRC = ./ft_atoi.c ./ft_memccpy.c ./ft_strcat.c ./ft_strncpy.c ./ft_bzero.c \
	   ./ft_memchr.c ./ft_strchr.c ./ft_strnequ.c ./ft_foreach.c \
	   ./ft_memcmp.c ./ft_strclr.c ./ft_strnew.c \
	   ./ft_memcpy.c ./ft_strcmp.c ./ft_strnstr.c ./ft_isalnum.c \
	   ./ft_strcpy.c ./ft_strrchr.c ./ft_isalpha.c \
	   ./ft_memdel.c ./ft_strdel.c ./ft_isascii.c \
	   ./ft_memmove.c ./ft_strdup.c ./ft_strsplit.c ./ft_isdigit.c \
	   ./ft_memset.c ./ft_strequ.c ./ft_strstr.c ./ft_isprint.c \
	   ./ft_putchar.c ./ft_striter.c ./ft_strsub.c ./ft_itoa.c \
	   ./ft_putchar_fd.c ./ft_striteri.c ./ft_strtrim.c ./ft_lstadd.c \
	   ./ft_putendl.c ./ft_strjoin.c ./ft_swap.c ./ft_lstdel.c \
	   ./ft_putendl_fd.c ./ft_strlcat.c ./ft_tolower.c ./ft_lstdelone.c	\
	   ./ft_putnbr.c ./ft_strlen.c ./ft_toupper.c ./ft_lstiter.c \
	   ./ft_putnbr_fd.c ./ft_strmap.c ft_lstmap.c ./ft_putstr.c \
	   ./ft_strmapi.c ./ft_lstnew.c ./ft_putstr_fd.c ./ft_strncat.c \
	   ./ft_memalloc.c  ./ft_strncmp.c ./get_next_line.c

SRCO = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRCO)
	@ar rc $(NAME) $(SRCO)
%.o: %.c gcc $(FLAGS) $< -o $@

clean:
			@rm -f $(SRCO)

fclean: clean
			@rm -f $(NAME)
	
re: fclean all

