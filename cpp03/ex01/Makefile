# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gouz <gouz@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 15:58:39 by nmorandi          #+#    #+#              #
#    Updated: 2023/08/30 11:48:34 by gouz             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ScavTrap
CC=c++
CFLAGS=-Wall -Werror -Wextra -std=c++98

FILES=main.cpp\
	ClapTrap.cpp\
	ScavTrap.cpp\

OBJ=$(FILES:.cpp=.o)

%.o : %.cpp
	$(CC) -c $(CFLAGS) -o $@ $<

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
