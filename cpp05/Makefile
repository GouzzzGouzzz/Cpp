# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gouz <gouz@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 15:58:39 by nmorandi          #+#    #+#              #
#    Updated: 2023/10/06 17:02:19 by gouz             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=Bureaucrat
CC=c++
CFLAGS=-g -Wall -Werror -Wextra -std=c++98

FILES=main.cpp\
	Bureaucrat.cpp\

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
