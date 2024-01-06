# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 17:06:53 by amalbrei          #+#    #+#              #
#    Updated: 2023/05/14 11:41:17 by amalbrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf
CC		=	gcc -g3
SUBDIR	=	libft
SUBLIB	=	ft
CFLAGS	=	-Wall -Wextra -Werror -Ofast
RM		=	rm	-rf

SRCS 	=	fdf.c\
			read_file.c\
			read_color.c\
			error_free.c\
			more_free.c\
			utility.c\
			draw.c\
			rotate.c\

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@
	
OBJS	= 	$(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) all -C mlx
	$(MAKE) all -C libft
	$(MAKE) gnl -C libft
	cd mlx && cp libmlx.dylib ..
	$(CC) $(CFLAGS) $(OBJS) -Llibft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	$(RM) $(OBJS) libmlx.dylib
	$(MAKE) clean -C mlx
	$(MAKE) clean -C libft

fclean: clean
	$(MAKE) fclean -C libft
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY = all clean fclean re
