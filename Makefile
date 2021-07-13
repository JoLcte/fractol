# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/15 23:17:06 by jlecomte          #+#    #+#              #
#    Updated: 2021/07/13 20:26:08 by jlecomte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CCF = clang -Wall -Wextra -Werror -g3
FLAGS = -Lmlx_linux -lmlx_Linux -lXext -lX11 -lm -lbsd

OBJ_DIR = obj
SRC_DIR = srcs

SRC_F = render.c\
		fractol.c

SRC = $(addprefix $(SRC_DIR)/,$(SRC_F))
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC_F:%.c=%.o))

HEADER = includes

all: $(NAME)


$(NAME) : $(OBJ)
	@echo "\e[38;5;38m *** CREATING MLX LIBRARY ***\e[m"
	@make -C mlx_linux
	@$(CCF) -o $(NAME) $(OBJ) $(FLAGS)
	@echo "\e[38;5;38m- Fractol Compilation Complete -"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CCF) -I /usr/include -I mlx_linux -I $(HEADER) -O3 -c $< -o $@
	@echo "\e[38;5;104mCreated: $(@:%=%)"

clean:
	@rm -rf mlx_linux/obj
	@echo "\e[38;5;125mRemoved MLX_LINUX Object Files"
	@rm -rf $(OBJ_DIR)
	@echo "\e[38;5;125mRemoved Object Files"

fclean: clean
	# @echo "\e[38;5;161mRemoved - MLX_LINUX Library -\e[m"
	# @rm -f mlx_linux/libmlx.a mlx_mlx_Linux.a
	@rm -f $(NAME)
	@echo "\e[38;5;161mRemoved - $(NAME) -"

re: fclean all

.PHONY: all clean fclean re
