# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahinani <ahinani@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/18 16:33:34 by ahinani           #+#    #+#              #
#    Updated: 2022/07/24 19:56:31 by ahinani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MINISHELL		=		builtins/ft_echo.c		\
						builtins/ft_env.c		\
						builtins/ft_pwd.c		\
						builtins/ft_exit.c		\
						execution/builtins.c	\
						utils/ft_free.c			\
						minishell.c
					


OBJ		=	$(MINISHELL:.c=.o)

CC			=	gcc
RM			=	rm -rf
CFLAGS		=	-Wall -Wextra -Werror
NAME		=	minishell
HEADER		=	include/minishell.h
LIBFT		=	libft/libft.a

all			:	$(NAME) $(LIBFT)

$(NAME)		:	$(OBJ) $(HEADER) $(LIBFT)
	@$(CC) $(CFLAGS) $(LIBFT) -L $(shell brew --prefix readline)/lib -lreadline -I include $(OBJ) -o $@
	@echo "\n\033[3m\033[2;32m[+]\033[2;37m	minishell file was created succesfully ✅\033[0m\n"
	
%.o			:	%.c $(HEADER)
	@$(CC) $(CFLAGS) -I $(shell brew --prefix readline)/include -c $< -o $(<:.c=.o)

$(LIBFT)		:
	@make all -C libft -s

clean		:
	@make clean -C libft
	@$(RM) $(OBJ)
	@echo "\n\033[3m\033[2;32m[+]\033[2;37m	.o has been removed succesfully ✅\033[0m\n"
	
	
fclean		:
	@make fclean -C libft
	@$(RM) $(OBJ)
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)
	@echo "\n\033[3m\033[2;32m[+]\033[2;37m	.o and minishell has been removed succesfully ✅\033[0m\n"
	

re			:	fclean all

.PHONY		:	all bonus re clean fclean