# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/10 14:45:40 by mkivipur          #+#    #+#              #
#    Updated: 2020/01/14 14:30:31 by mkivipur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = ./sources/main.c ./sources/get_next_line.c ./sources/get_coordinates.c
OBJS = ./*.o

MLX		= ./miniLibX/
MLX_LIB	= $(addprefix $(MLX),mlx.a)
MLX_INC	= -I ./miniLibX
MLX_LNK	= -L ./miniLibX -l mlx -framework OpenGL -framework AppKit

HDR = ./sources/ 

LIBFT = libft/

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	make -C $(LIBFT)
	gcc $(FLAGS) -o $(NAME) $(MLX_INC) $(MLX_LNK) $(SRCS) -I $(HDR) -L. libft/libft.a
clean:
	/bin/rm -f $(OBJ)
	make -C $(LIBFT) clean
fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIBFT) fclean
re: fclean all
