# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/11 11:41:51 by hrothery          #+#    #+#              #
#    Updated: 2022/04/20 17:03:04 by hrothery         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo 

SRC = check_data.c eat_cycle.c error.c init.c mutex.c timestamp.c \
		utils.c hands.c

OBJ = $(SRC:.c=.o) 

CC = gcc 

CFLAGS = -pthread -Wall -Wextra -Werror #-fsanitize=thread

all: $(NAME) 

$(NAME): $(OBJ) $(SRC)
	$(CC) $(CFLAGS) $(OBJ) -o $@

clean:
	rm -f $(OBJ) 

fclean: clean 
	rm -f $(NAME) 

re: fclean all