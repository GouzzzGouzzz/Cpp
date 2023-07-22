# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gouz <gouz@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 15:58:39 by nmorandi          #+#    #+#              #
#    Updated: 2023/07/22 17:29:22 by gouz             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=AbstractClass
CC=g++
CFLAGS=-Wall -Werror -Wextra -std=c++98 -g

FILES=main.cpp\
	Dog.cpp\
	Cat.cpp\
	AAnimal.cpp\
	Brain.cpp\
	WrongAnimal.cpp\
	WrongCat.cpp\

OBJ=$(FILES:.cpp=.o)

%.o : %.c
	$(CC) -c $(CFLAGS) -o $@ $<

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
