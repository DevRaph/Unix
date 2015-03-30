# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpinet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/30 12:38:29 by rpinet            #+#    #+#              #
#    Updated: 2015/03/30 12:44:32 by rpinet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_p.a

FLAG = -Wall -Wextra -Werror

SRC =	ft_builtin.c \
		ft_fork.c \
		ft_pwd.c \
		ft_exec.c \
		ft_put.c \
		ft_get.c \
		ft_tools.c

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
	@rm -rf serveur

	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

re: fclean all

