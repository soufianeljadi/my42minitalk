# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-jadi <sel-jadi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 11:54:51 by sel-jadi          #+#    #+#              #
#    Updated: 2024/01/05 00:53:36 by sel-jadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

NAME_S = server
NAME_C = client
NAME_SBONUS = server_bonus
NAME_CBONUS = client_bonus

COMM_SRC = ft_printf.c ft_printf_utils.c ft_atoi.c
SRC_S = server.c 
SRC_C = client.c 
SRC_SB = server_bonus.c 
SRC_CB = client_bonus.c 

COMM_OBJ = $(COMM_SRC:.c=.o)
OBJ_S = $(SRC_S:.c=.o)
OBJ_C = $(SRC_C:.c=.o)
OBJ_SB = $(SRC_SB:.c=.o)
OBJ_CB = $(SRC_CB:.c=.o)

%.o: %.c minitalk.h
	@ $(CC) $(FLAGS) -o $@ -c $<
	
all: client server

server: $(OBJ_S) $(COMM_OBJ)
	@ $(CC) $(FLAGS) $(COMM_OBJ) $(OBJ_S) -o $(NAME_S)

client: $(OBJ_C) $(COMM_OBJ)
	@ $(CC) $(FLAGS) $(COMM_OBJ) $(OBJ_C) -o $(NAME_C)

bonus: client_bonus server_bonus

client_bonus: $(OBJ_CB) $(COMM_OBJ)
	@ $(CC) $(FLAGS) $(COMM_OBJ) $(OBJ_CB) -o $(NAME_CBONUS)

server_bonus: $(OBJ_SB) $(COMM_OBJ)
	@ $(CC) $(FLAGS) $(COMM_OBJ) $(OBJ_SB) -o $(NAME_SBONUS)

clean:
	@ $(RM) $(OBJ_S) $(OBJ_C) $(OBJ_SB) $(OBJ_CB) $(COMM_OBJ)

fclean: clean
	@ $(RM) $(NAME_S) $(NAME_C) $(NAME_SBONUS) $(NAME_CBONUS)

re: clean all

.PHONY: clean all fclean re bonus 