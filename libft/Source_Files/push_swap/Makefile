# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/28 11:13:35 by amalbrei          #+#    #+#              #
#    Updated: 2022/09/28 14:53:38 by amalbrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEFAULT	=	\033[0m
RED		=	\033[1;31m
GREEN	=	\033[1;32m
YELLOW	=	\033[1;33m
PURPLE	=	\033[0;35m
CYAN	=	\033[1;36m

NAME	=	push_swap
CC		=	gcc
SUBDIR	=	libft
SUBLIB	=	ft
CFLAGS	=	-Wall -Wextra -Werror -g3
RM		=	rm	-rf

SRCS 	=	push_swap.c\
			ps_prep_numbers.c\
			ps_check_error.c\
			ps_parse_numbers.c\
			ps_free.c\
			ps_swap.c\
			ps_push.c\
			ps_rotate.c\
			ps_rev_rotate.c\
			ps_choose_algo.c\
			ps_algo_list.c\
			ps_algo_list2.c\
			ps_algo_list3.c\
			ps_chunker.c\

all: $(NAME)

%.o: %.c
	@printf "\033[A\033[2K\r$(GREEN)Compiling: "
	$(CC) $(CFLAGS) -c $< -o $@
	@printf "🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇"
	
OBJS	= 	$(SRCS:.c=.o)

$(NAME): $(OBJS)
	@$(MAKE) all -C libft
	@printf "$(CYAN)\n==========================\n"
	@printf "$(CYAN) PROGRAM CREATED\n"
	@printf "$(CYAN)==========================\n"
	@$(CC) $(CFLAGS) $(OBJS) -Llibft -lft -o $(NAME)

clean:
	@printf "$(RED)CLEANING PUSH_SWAP.O FILES\n"
	@$(MAKE) clean -C libft
	@$(RM) $(OBJS)

fclean: clean
	@printf "$(RED)CLEANING PUSH_SWAP PROGRAM\n"
	@$(MAKE) fclean -C libft
	@$(RM) $(NAME)

re: fclean $(NAME)

.PHONY = all clean fclean re
