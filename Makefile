# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmorales <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/08 01:20:50 by fmorales          #+#    #+#              #
#    Updated: 2014/03/08 03:34:03 by fmorales         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MKEX = cc -o
SRC = 	main.c getnextline.c
FLAGS = -Wall -Wextra -Werror
OBJECT = $(SRC:.c=.o)
COMP = cc -c
NAME = puissance4

all : $(NAME)

$(NAME) : $(OBJECT)
			@$(MKEX) $(NAME) $(OBJECT) -L libft/ -lft

$(OBJECT) :
			make -C libft/
			@$(COMP) $(SRC) $(FLAGS)
			@echo "Compilation of C files succesful"

clean :
			/bin/rm -f $(OBJECT)
			@echo "Object deleted"


fclean : clean
			/bin/rm -f $(NAME)
			@echo "Folder cleanup successful"

re : fclean all
