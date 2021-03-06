# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 21:57:52 by ybenoit           #+#    #+#              #
#    Updated: 2017/06/27 14:28:10 by ybenoit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC=gcc
NAME=libftprintf.a

INCLUDES=./includes

SRC_DIR=srcs
SRC_BASE=fun_printf/ft_additfun.c\
			fun_printf/ft_additfun2.c\
			fun_printf/ft_additfun3.c\
			fun_printf/ft_precision.c\
			fun_printf/ft_putarg.c\
			fun_printf/ft_putarg2.c\
			fun_printf/wchar_fun.c\
			fun_printf/ft_flags.c\
			fun_printf/ft_flags2.c\
			fun_printf/ft_printf.c\
			fun_printf/ft_args.c\
			fun_printf/ft_parsing.c\
			fun_printf/ft_function.c\
			fun_printf/ft_parsarg.c\
			fun_printf/ft_ctransformer.c\
			ft_atoi.c\
			ft_bzero.c\
			ft_char_count.c\
			ft_cp_new_elem.c\
			ft_isalnum.c\
			ft_isalpha.c\
			ft_isascii.c\
			ft_isblank.c\
			ft_isdigit.c\
			ft_isprint.c\
			ft_isspace.c\
			ft_isxdigit.c\
			ft_itoa.c\
			ft_itoabase.c\
			ft_lstadd.c\
			ft_lstdel.c\
			ft_lstdelone.c\
			ft_lstiter.c\
			ft_lstmap.c\
			ft_lstnew.c\
			ft_memalloc.c\
			ft_memccpy.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_memcpy.c\
			ft_memdel.c\
			ft_memmove.c\
			ft_memset.c\
			ft_next_char.c\
			ft_num_count.c\
			ft_pow.c\
			ft_pow10.c\
			ft_powf.c\
			ft_putchar.c\
			ft_putchar_fd.c\
			ft_putendl.c\
			ft_putendl_fd.c\
			ft_putlong.c\
			ft_putnbr.c\
			ft_putnbr_fd.c\
			ft_putstr.c\
			ft_putstr_fd.c\
			ft_strcat.c\
			ft_strchr.c\
			ft_strclr.c\
			ft_strcmp.c\
			ft_strcpy.c\
			ft_strdel.c\
			ft_strdup.c\
			ft_strequ.c\
			ft_striter.c\
			ft_striteri.c\
			ft_strjoin.c\
			ft_strlcat.c\
			ft_strlen.c\
			ft_strmap.c\
			ft_strmapi.c\
			ft_strncat.c\
			ft_strncmp.c\
			ft_strncpy.c\
			ft_strnequ.c\
			ft_strnew.c\
			ft_strnstr.c\
			ft_strpbrk.c\
			ft_strrchr.c\
			ft_strrev.c\
			ft_strsplit.c\
			ft_strstr.c\
			ft_strsub.c\
			ft_strtrim.c\
			ft_tolower.c\
			ft_toupper.c\
			ft_word_count.c\
			get_next_line.c\
			ft_strlen_c.c\
			ft_strdup_c.c\
			ft_strndup.c\
			ft_strjoin_free.c\
			ft_sstrlen.c\
			ft_sstradd.c\
			ft_itoabase_uint.c\
			ft_str_resize.c\
			ft_str_resize_nf.c\
			ft_strmaj.c


#PREFIXE
SRCS=$(addprefix $(SRC_DIR)/, $(SRC_BASE))
OBJS=$(addprefix $(SRC_DIR)/, $(SRC_BASE:.c=.o))

#COLORS
C_NO="\033[00m"
C_OK="\033[32m"
C_GOOD="\033[32m"
C_ERROR="\033[31m"
C_WARN="\033[33m"

#DEBUG
SUCCESS=$(C_GOOD)SUCCESS$(C_NO)
OK=$(C_OK)OK$(C_NO)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "Compiling" [ $(NAME) ] $(SUCCESS)

%.o: %.c $(INCLUDES)/libft.h $(INCLUDES)/ft_printf.h
	@$(CC) -c -o $@ $< -I $(INCLUDES)

clean:
	@rm -f $(OBJS)
	@echo "Cleaning" [ $(NAME) ] "..." $(OK)

fclean: clean
	@rm -f $(NAME)
	@rm -f ./srcs/libft.a
	@echo "Delete" [ $(NAME) ] $(OK)


re: fclean all


.PHONY: clean all re fclean
