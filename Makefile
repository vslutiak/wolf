# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vslutiak <vslutiak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/18 21:20:37 by vslutiak          #+#    #+#              #
#    Updated: 2019/07/18 21:32:01 by vslutiak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC_DIR = ./srcs/
OBJ_DIR = ./
INC_DIR = ./includes/
LIB_DIR = ./libft/
HEADERS = $(INC_DIR)wolf.h

SRC = main.c hook.c rcast.c reader.c check.c

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

CC = gcc  -I ~/Library/Frameworks/SDL2.framework/Versions/A/Headers -F ~/Library/Frameworks \
 -I ~/Library/Frameworks/SDL2_mixer.framework/Versions/A/Headers -F ~/Library/Frameworks/ \
 -I ~/Library/Frameworks/SDL2_image.framework/Versions/A/Headers -F ~/Library/Frameworks/

FLAGS = -framework SDL2 -framework SDL2_mixer -framework SDL2_image

LIBFT_DIR = $(LIB_DIR)
LIBFT = $(LIBFT_DIR)libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_DIR)
	@$(CC) $(LIBFT) $(OBJ) $(FLAGS) -o $(NAME)

$(OBJ_DIR)%.o: %.c $(HEADERS) Makefile
	$(CC) -c $< -o $@ -I $(INC_DIR)

clean:
	rm -f $(OBJ)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

vpath %.c $(SRC_DIR)