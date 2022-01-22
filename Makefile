# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 13:12:56 by rlucio-l          #+#    #+#              #
#    Updated: 2022/01/22 11:33:42 by rlucio-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

CLIENT = client

SERVER = server

CLIENT_SRC = client.c

SERVER_SRC = server.c

CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

SERVER_OBJ = $(SERVER_SRC:.c=.o)

CC = gcc
CFLAGS += -Wall -Wextra -Werror -I./include

.c.o :
	$(CC) ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	all

all:	$(CLIENT) $(SERVER)

$(CLIENT):	$(CLIENT_OBJ)
			$(CC) -o $(CLIENT) $(CLIENT_OBJ)

$(SERVER):	$(SERVER_OBJ)
			$(CC) -o $(SERVER) $(SERVER_OBJ)

clean:
		rm -f $(CLIENT_OBJ) $(SERVER_OBJ)

fclean:	clean
		rm -f $(CLIENT) $(SERVER)

re:		fclean all

.PHONY: all clean fclean re
