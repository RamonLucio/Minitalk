# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 13:12:56 by rlucio-l          #+#    #+#              #
#    Updated: 2022/02/11 18:28:44 by rlucio-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

CLIENT = client
SERVER = server
CLIENT_SRC = client.c
SERVER_SRC = server.c

CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus
CLIENT_SRC_BONUS = client_bonus.c
SERVER_SRC_BONUS = server_bonus.c

CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

SERVER_OBJ = $(SERVER_SRC:.c=.o)

CLIENT_OBJ_BONUS = $(CLIENT_SRC_BONUS:.c=.o)

SERVER_OBJ_BONUS = $(SERVER_SRC_BONUS:.c=.o)

CC = gcc
CFLAGS += -Wall -Wextra -Werror -I ./include

.c.o :
	$(CC) ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	all

all:	$(LIBFT) $(CLIENT) $(SERVER)

$(LIBFT):
			make -C $(LIBFT_DIR)

$(CLIENT):	$(CLIENT_OBJ)
			$(CC) -o $(CLIENT) $(CLIENT_OBJ) $(LIBFT)

$(SERVER):	$(SERVER_OBJ)
			$(CC) -o $(SERVER) $(SERVER_OBJ) $(LIBFT)

bonus:	$(LIBFT) $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT_BONUS):	$(CLIENT_OBJ_BONUS)
					$(CC) -o $(CLIENT_BONUS) $(CLIENT_OBJ_BONUS) $(LIBFT)

$(SERVER_BONUS):	$(SERVER_OBJ_BONUS)
					$(CC) -o $(SERVER_BONUS) $(SERVER_OBJ_BONUS) $(LIBFT)

clean:
		make -C $(LIBFT_DIR) clean
		rm -f $(CLIENT_OBJ) $(SERVER_OBJ)
		rm -f $(CLIENT_OBJ_BONUS) $(SERVER_OBJ_BONUS)

fclean:	clean
		make -C $(LIBFT_DIR) fclean
		rm -f $(CLIENT) $(SERVER)
		rm -f $(CLIENT_BONUS) $(SERVER_BONUS)

re:		fclean all

.PHONY: all clean fclean re libft bonus
