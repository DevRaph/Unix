# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpinet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/22 17:50:16 by rpinet            #+#    #+#              #
#    Updated: 2015/01/22 17:50:21 by rpinet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAG = -Wall -Werror -Wextra

SRC = 	ft_abs.c ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	ft_isdigit.c ft_islower.c ft_isprint.c ft_isspace.c ft_isupper.c \
	ft_itoa.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c \
	ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c \
	ft_putstr_fd.c ft_rotone.c ft_rotone_x.c ft_strcat.c ft_strchr.c \
	ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c \
	ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c \
	ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c \
	ft_strndup.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c \
	ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_swap.c \
	ft_tolower.c ft_toupper.c \
	ft_mallocat.c ft_strcjoin.c ft_strcutdup.c get_next_line.c \
	ft_atoi_base.c ft_convert_base.c ft_get_base.c ft_strpos.c \
	ft_nbrlen.c \
	ft_lst_push_back.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstdelone.c \
	ft_lstiter.c ft_lstmap.c ft_lstnew.c \
	ft_print_tab.c ft_error.c ft_size_tab.c\
	ft_shellcolors.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@gcc $(FLAG) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@echo "\033[35;1m• \033[0mRemoving object files in libft ...\033[55G\c"
	@rm -f $(OBJ)
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

fclean: clean
	@echo "\033[35;1m• \033[0mRemoving $(NAME) ...\033[55G\c"
	@rm -rf $(NAME)
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

re: fclean all
