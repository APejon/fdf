# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 19:43:26 by amalbrei          #+#    #+#              #
#    Updated: 2022/10/05 18:39:13 by amalbrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEFAULT	=	\033[0m
RED		=	\033[1;31m
GREEN	=	\033[1;32m
YELLOW	=	\033[1;33m
PURPLE	=	\033[0;35m
CYAN	=	\033[1;36m

NAME	=	libft.a
SRC_DIR	=	Source_Files
OBJ_DIR	=	Object_Files
INC_DIR =	Includes
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
LIB		=	ar	-rcs
RM		=	rm	-rf

SRCS 	= 	ft_isalpha.c	ft_isdigit.c	ft_isalnum.c	ft_isascii.c	\
			ft_isprint.c	ft_strlen.c		ft_memset.c		ft_bzero.c		\
			ft_memcpy.c		ft_memmove.c	ft_strlcpy.c	ft_strlcat.c	\
			ft_toupper.c	ft_tolower.c	ft_strchr.c		ft_strrchr.c	\
			ft_strncmp.c	ft_memchr.c		ft_memcmp.c		ft_strnstr.c	\
			ft_atoi.c		ft_calloc.c		ft_strdup.c		ft_substr.c		\
			ft_strjoin.c	ft_strtrim.c	ft_strmapi.c	ft_striteri.c	\
			ft_putchar_fd.c	ft_putstr_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c	\
			ft_itoa.c		ft_split.c		ft_check_doublequotes.c			\
			ft_check_arguments.c	ft_error_msg.c
			
B_SRCS 	=	ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c	ft_lstlast.c\
			ft_lstdelone.c	ft_lstadd_back.c	ft_lstclear.c	ft_lstiter.c\
			ft_lstmap.c

F_SRCS 	= 	pt_printf.c			pt_allocate.c		pt_putchar_arg.c		\
			pt_putpointer_arg.c	pt_puthexa_arg.c	pt_uputnbr_arg.c		\
			pt_putnbr_arg.c		pt_putstr_arg.c		pt_putpercent_arg.c		\
			pt_createflag.c		pt_isflag.c			pt_nlen.c				\
			pt_addspaces.c		pt_fn.c

G_SRCS 	= 	get_next_line.c	get_next_line_utils.c	get_next_line_bonus.c	\
			get_next_line_utils_bonus.c

OBJ		= 	$(addprefix $(OBJ_DIR)/, $(SRCS:%c=%o))

B_OBJ	=	$(addprefix $(OBJ_DIR)/, $(B_SRCS:%c=%o))

F_OBJ	=	$(addprefix $(OBJ_DIR)/, $(F_SRCS:%c=%o))

G_OBJ	=	$(addprefix $(OBJ_DIR)/, $(G_SRCS:%c=%o))


all: $(NAME)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf "\033[A\033[2K\r$(GREEN)Compiling:"
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@
	@printf "🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇🏇"

$(NAME): $(OBJ)
	@printf "$(CYAN)\n==========================\n"
	@printf "LIBFT COMPILED\n"
	@printf "$(CYAN)==========================\n"
	@$(LIB) $(NAME) $(OBJ)
	
bonus: $(B_OBJ)
	@printf "$(CYAN)\n==========================\n"
	@printf "LIBFT BONUS COMPILED\n"
	@printf "$(CYAN)==========================\n"
	@$(LIB) $(NAME) $(B_OBJ)

printf: $(F_OBJ)
	@printf "$(CYAN)\n==========================\n"
	@printf "PRINTF COMPILED\n"
	@printf "$(CYAN)==========================\n"
	@$(LIB) $(NAME) $(F_OBJ)

gnl: $(G_OBJ)
	@printf "$(CYAN)\n==========================\n"
	@printf "GET_NEXT_LINE COMPILED\n"
	@printf "$(CYAN)==========================\n"
	@$(LIB) $(NAME) $(G_OBJ)

list:
	@ar -t $(NAME)
	@echo Object files above are within your library.

clean:
	@printf "$(RED)CLEANING *.O FILES\n"
	@$(RM) $(OBJ_DIR)

fclean: clean
	@printf "$(RED)CLEANING LIBFT.A LIBRARY\n"
	@$(RM) $(NAME)

re: fclean $(NAME)

.PHONY = all bonus printf gnl list clean fclean re
