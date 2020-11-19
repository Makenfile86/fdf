# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/10 14:45:40 by mkivipur          #+#    #+#              #
#    Updated: 2020/02/12 09:58:10 by mkivipur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = ./sources/main.c ./sources/read.c ./sources/init.c ./sources/get_next_line.c ./sources/error_messages.c ./sources/controls3.c ./sources/get_coordinates.c ./sources/adjust_data.c ./sources/move_coordinates.c ./sources/draw.c ./sources/support_f.c ./sources/move_points.c ./sources/error_check.c ./sources/color.c ./sources/controls.c ./sources/controls2.c

OBJS = ./*.o

MLX		= ./miniLibX/

LIBS	= -L libft/ -lft -L ./miniLibX -l mlx -framework OpenGL -framework AppKit

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS) 
	gcc $(OBJS) $(LIBS) -o $(NAME)

$(OBJS): $(SRCS) 
	$(CC) $(FLAGS) -c $(SRCS)
	make re -C ./libft/

clean:
	/bin/rm -f $(OBJS)
	make clean -C ./libft/
fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C ./libft/
re: fclean all
