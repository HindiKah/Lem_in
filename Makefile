# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/19 18:35:20 by ybenoit           #+#    #+#              #
#    Updated: 2017/05/11 15:54:10 by ybenoit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
NAME=lem-in

INCLUDES=./includes

SRC_DIR=srcs
SRC_BASE=main.c\
		 parsing.c\
		 read_file.c\
		 room_init.c\
		 init_liaison.c\
		 graph_init.c\
		 way.c\
		 tab_fun.c

SRCS=$(addprefix $(SRC_DIR)/, $(SRC_BASE))
OBJS=$(addprefix $(SRC_DIR)/, $(SRC_BASE:.c=.o))

C_NO="\033[00m"
C_OK="\033[32m"
C_GOOD="\033[32m"
C_ERROR="\033[31m"
C_WARN="\033[33m"

SUCCESS=$(C_GOOD)SUCCESS$(C_NO)
OK=$(C_OK)OK$(C_NO)

all: $(NAME)

$(NAME): libftprintf42 $(OBJS)
		$(CC) -o $(NAME) $(OBJS) libftprintf/libftprintf.a
		@echo "Compiling" [ $(NAME) ] $(SUCCESS)

%.o: %.c $(INCLUDES)/libft.h $(INCLUDES)/ft_printf.h
		@$(CC) -c -o $@ $< libftprintf/libftprintf.a -I $(INCLUDES)

libftprintf42:
			make -C ./libftprintf

clean:
		@rm -f $(OBJS)
		@make -C ./libftprintf clean
		@echo "Cleaning" [ $(NAME) ] "..." $(OK)

fclean: clean
		@rm -f $(NAME)
		@make -C ./libftprintf fclean
		@echo "Delete" [ $(NAME) ] $(OK)


re: fclean all


.PHONY: clean all re fclean
