# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpinet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/10 15:19:04 by rpinet            #+#    #+#              #
#    Updated: 2015/02/10 16:11:25 by rpinet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_minishell1

SRC = main_sh1.c

FLAG = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@make -C ./libft/ re
	@make -C ./srcs/ re
	@gcc -o $(NAME) $(SRC) srcs/sh1.a $(FLAG) -L libft -lft
	@echo "\n\tGO SH1\n\n"

clean:
	@rm -f $(OBJ)
	@make -C libft/ clean
	@make -C srcs/ clean
	@echo "\033[35;1m•   \033[0mRemoving object files in sh1 ...\033[55G\c"
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@make -C libft/ fclean
	@make -C srcs/ fclean
	@echo "\033[35;1m•   \033[0mRemoving $(NAME) ...\033[55G\c"
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

re: fclean all