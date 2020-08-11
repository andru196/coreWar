# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sfalia-f <sfalia-f@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/28 20:41:38 by ycorrupt          #+#    #+#              #
#    Updated: 2020/08/11 19:05:14 by sfalia-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	asm
DIR_ASM			=	./src/asm/
SRCS_ASM		=	asm_cor_init.c \
					asm_cpy_word.c \
					asm_translate.c \
					asm.c \
					cor_command_check.c \
					cor_label_check.c \
					init_struct.c \
					read_cor_file.c
SRCS			=	$(addprefix $(DIR_ASM), $(SRCS_ASM)) \
					src/op.c
OBJ				=	$(patsubst %.c, %.o, $(SRCS))
CC				=	clang
FLAGS			=	-Wall -Wextra -Werror -g
LIBRARY			=	src/libft/
LIBFT			=	$(LIBRARY)libft.a
HEADERS			=	includes/ $(LIBRARY)includes
INCLUDES		=	-I includes/ -I $(LIBRARY)includes

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) -L $(LIBRARY) -lft

$(LIBFT):
	make -C $(LIBRARY)

%.o : %.c $(HEADERS)
	$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(LIBRARY) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBRARY) fclean

re: fclean all