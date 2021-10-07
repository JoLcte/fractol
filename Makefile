# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/15 23:17:06 by jlecomte          #+#    #+#              #
#    Updated: 2021/10/07 16:41:53 by jlecomte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CCF = clang -Wall -Wextra -Werror 
FLAGS = -Lmlx_linux -lmlx_Linux -lXext -lX11 -lm -lpthread

OBJ_DIR = obj
SRC_DIR = src

SRC_F = burning_ship.c\
	additional_keys.c\
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

resol = 1000
cr = 0.285
ci = 0.010
n_max = 500
n_colors = 64
n_indexes = 16
CCF += -D RESOL=$(resol) -D CR=$(cr) -D CI=$(ci) -D N_MAX=$(n_max) -D N_COLORS=$(n_colors) -D N_INDEXES=$(n_indexes)


ON_BLUE = \033[44m
ON_CYAN = \033[46m
ON_PURPLE = \033[45m
BBLUE = \033[1;34m
BCYAN = \033[1;36m
BGREEN = \033[1;32m
BLUE = \033[0;34m
CYAN = \033[0;36m
PURPLE = \033[0;35m
COLORS_OFF = \033[m





all: $(NAME)


$(NAME) : $(OBJ)
	@echo "$(ON_BLUE) *** Compiling MLX Library ***$(COLORS_OFF)"
	@make -C mlx_linux
	@$(CCF) -o $(NAME) $(OBJ) $(FLAGS)
	@echo "$(ON_BLUE)- $(NAME) Compilation Completed -$(COLORS_OFF)"
	@echo "$(ON_CYAN)		***  Welcome in FRACT_OL !***$(COLORS_OFF)"
	@echo "$(BCYAN)You can choose the following options while make re:$(COLORS_OFF)"
	@echo "--->  $(BGREEN)resol=XX $(BLUE)to select the square resolution (1000 by default)"
	@echo "--->  $(BGREEN)n_max=XX $(BLUE)to select the max loops number (500 by default)"
	@echo "$(BBLUE)--->  $(BGREEN)cr=XX ci=XX $(BLUE)to choose Julia constant"
	@echo "$(BBLUE)--->  $(BGREEN)n_colors=XX n_indexes=XX $(BLUE)to chose the colors details."
	@echo "      N_COLORS is the number of total colors the program will use"
	@echo "      N_INDEXES is the number of gradient colors between two colors"
	@echo "      in the palette (cf palette.c). Both numbers must be >= 16"
	@echo "$(BBLUE)ex: $(BGREEN)make re resol=400 cr=-0.4 ci=0.6$(COLORS_OFF)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CCF) -I /usr/include -I mlx_linux -I $(HEADER) -O3 -c $< -o $@
	@echo "$(CYAN)Creating: $(@:%=%)$(COLORS_OFF)"

clean:
	@if [ -d mlx_linux/obj ]; then rm -rf mlx_linux/obj && echo "$(PURPLE)Removing: mlx_linux Object Files$(COLORS_OFF)"; else echo "make: No mlx_linux objects to remove."; fi;
	@if [ -d $(OBJ_DIR) ]; then rm -rf $(OBJ_DIR) && echo "$(PURPLE)Removing: $(NAME) Object Files$(COLORS_OFF)"; else echo "make: No $(NAME) objects to remove."; fi

fclean: clean
	@if [ -f mlx_linux/libmlx.a ]; then rm -f mlx_linux/libmlx.a mlx_mlx_Linux.a && echo "$(ON_PURPLE)Removing - libmlx Library -$(COLORS_OFF)"; else echo "make: No libmlx to remove."; fi;
	@if [ -f mlx_linux/libmlx_Linux.a ]; then rm -f mlx_linux/libmlx_Linux.a && echo "$(ON_PURPLE)Removing - libmlx_Linux Library -$(COLORS_OFF)"; else echo "make: No libmlx_Linux to remove."; fi;
	@if [ -f $(NAME) ]; then rm -f $(NAME) && echo "$(ON_PURPLE)Removing - $(NAME) -$(COLORS_OFF)"; else echo "make: No binary $(NAME) to remove."; fi;

re: fclean all

.PHONY: all clean fclean re
