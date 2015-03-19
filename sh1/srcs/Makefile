# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpinet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/19 20:16:12 by rpinet            #+#    #+#              #
#    Updated: 2015/02/19 20:16:16 by rpinet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = sh1.a

FLAG = -Wall -Wextra -Werror

SRC = 	ft_minishell1.c \
		ft_builtin.c \
		ft_exec.c \
		ft_env.c \
		ft_setenv.c \
		ft_unsetenv.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@gcc $(FLAG) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@echo "\033[35;1m• \033[0mRemoving object files in srcs ...\033[55G\c"
	@rm -f $(OBJ)
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

fclean: clean
	@echo "\033[35;1m• \033[0mRemoving $(NAME) ...\033[55G\c"
	@rm -rf $(NAME)
	@rm -rf ft_minishell1
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

re: fclean all