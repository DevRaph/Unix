# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpinet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/30 12:45:07 by rpinet            #+#    #+#              #
#    Updated: 2015/03/30 12:50:53 by rpinet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = serveur
NAME2 = srcs/client

SRC1 = srcs/serveur.c
SRC2 = srcs/client.c

FLAG = -Wall -Werror -Wextra

OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)

all: $(NAME1)

$(NAME1):
	@make -C ./libft/ re
	@make -C ./srcs/ re
	@gcc -o $(NAME1) $(SRC1) srcs/ft_p.a $(FLAG) -L libft -lft
	@gcc -o $(NAME2) $(SRC2) srcs/ft_p.a $(FLAG) -L libft -lft
	@echo "\n\tRUN MY SERVEUR, CLIENT IS IN SRCS\n\n"

clean:
	@rm -f $(OBJ1)
	@rm -f $(OBJ2)
	@make -C libft/ clean
	@make -C srcs/ clean
	@echo "\033[35;1m•   \033[0mRemoving object files in ft_p ...\033[55G\c"
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

fclean: clean
	@rm -rf $(NAME1)
	@rm -rf $(NAME2)
	@make -C libft/ fclean
	@make -C srcs/ fclean
	@echo "\033[35;1m•   \033[0mRemoving $(NAME1) and $(NAME2) ...\033[55G\c"
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

re: fclean all
