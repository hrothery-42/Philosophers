# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 07:59:43 by hrothery          #+#    #+#              #
#    Updated: 2022/04/21 08:14:15 by hrothery         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus 

SRC =	initialize.c \
		error.c \
		check_data.c \
		create_processes.c \
		utils.c \
		timestamp.c \
		free.c \
		main.c \

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