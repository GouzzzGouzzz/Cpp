# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gouz <gouz@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 15:58:39 by nmorandi          #+#    #+#              #
#    Updated: 2023/05/10 21:25:16 by gouz             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=harlFilter
CC=g++
CFLAGS=-Wall -Werror -Wextra -std=c++98

FILES=main.cpp\
	HarlClass.cpp\

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
