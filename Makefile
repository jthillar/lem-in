# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/16 16:49:02 by jthillar          #+#    #+#              #
#    Updated: 2017/10/03 15:54:10 by jthillar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = lem-in

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

LIB = libft

LDFLAGS = -Llibft

LDLIBS = -lft

SRC_PATH = srcs

SRC_NAME = main.c parsing.c parsing2.c fill_list.c add_tube.c error.c algo.c \
			print_result.c result_ants.c aglo_parsing_main.c

AR = ar rc

INC_LIB = -I libft/includes

CPPFLAGS = -I includes

OBJ_PATH = obj

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))


all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB)
	@echo $(NAME) ": Compilation des sources..."
	@$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS) $(LDLIBS)
	@echo "Executable "$(NAME)" du checker fait"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(INC_LIB) -o $@ -c $<


clean:
	@make fclean -C $(LIB)
	@rm -f $(OBJ)
	@rm -rf $(OBJ_PATH) || true
	@echo $(OBJ_PATH)" supprimé"

fclean: clean
	@rm -f $(NAME)
	@echo "Executable de "$(NAME)" supprimé !"

re: fclean all
	@echo "Make re realise!"
