# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/15 23:17:06 by jlecomte          #+#    #+#              #
#    Updated: 2021/10/05 18:31:56 by jlecomte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CCF = clang -Wall -Wextra -Werror -O3
FLAGS = -Lmlx_linux -lmlx_Linux -lXext -lX11 -lm -lpthread

OBJ_DIR = obj
SRC_DIR = src

SRC_F = additional_keys.c\
	burning_ship.c\
	colors.c\
	error.c\
	key_move.c\
	init.c\
	julia.c\
	mandelbrot.c\
	mlx_utils.c\
	palette.c\
	parse.c\
	print.c\
	zoom.c\
	fractol.c
SRC = $(addprefix $(SRC_DIR)/,$(SRC_F))
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC_F:%.c=%.o))

HEADER = includes
cr = 0.285
ci = 0.010
n_colors = 64
n_indexes = 16
CCF += -D CR=$(cr) -D CI=$(ci) -D N_COLORS=$(n_colors) -D N_INDEXES=$(n_indexes)

all: $(NAME)


$(NAME) : $(OBJ)
	@echo "\033[44m *** Compiling MLX Library ***\033[m"
	@make -C mlx_linux
	@$(CCF) -o $(NAME) $(OBJ) $(FLAGS)
	@echo "\033[44mm- $(NAME) Compilation Completed -\033[m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CCF) -I /usr/include -I mlx_linux -I $(HEADER) -O3 -c $< -o $@
	@echo "\033[0;36mCreating: $(@:%=%)\033[m"

clean:
	@if [ -d mlx_linux/obj ]; then rm -rf mlx_linux/obj && echo "\033[0;35mRemoving: mlx_linux Object Files\033[m"; else echo "make: No mlx_linux objects to remove."; fi;
	@if [ -d $(OBJ_DIR) ]; then rm -rf $(OBJ_DIR) && echo "\033[0;35mRemoving: $(NAME) Object Files\033[m"; else echo "make: No $(NAME) objects to remove."; fi

fclean: clean
	@if [ -f mlx_linux/libmlx.a ]; then rm -f mlx_linux/libmlx.a mlx_mlx_Linux.a && echo "\033[45mRemoving - libmlx Library -\033[m"; else echo "make: No libmlx to remove."; fi;
	@if [ -f mlx_linux/libmlx_Linux.a ]; then rm -f mlx_linux/libmlx_Linux.a && echo "\033[45mRemoving - libmlx_Linux Library -\033[m"; else echo "make: No libmlx_Linux to remove."; fi;
	@if [ -f $(NAME) ]; then rm -f $(NAME) && echo "\033[45mRemoving - $(NAME) -\033[m"; else echo "make: No binary $(NAME) to remove."; fi;

re: fclean all

.PHONY: all clean fclean re
