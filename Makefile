# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hankhali <hankhali@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 15:47:48 by hankhali          #+#    #+#              #
#    Updated: 2024/02/19 21:32:20 by hankhali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

FILES = error.c main.c split.c stack_init.c p.c rrrs.c rs.c sort_stacks.c sort_three.c swap.c init_a_to_b.c init_b_to_a.c stack_utils.c sort_stacks2.c help.c
OBJ = $(FILES:.c=.o)

FT_PRINTF = ft_printf/
INCLUDE = -L ./ft_printf -lftprintf

CC = cc
CFLAGS = -Wall -Werror -Wextra

all :$(NAME)
$(NAME): $(OBJ)
	make -C $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(INCLUDE)

clean:
	rm -f $(OBJ)
	make -C $(FT_PRINTF) clean

fclean: clean
	rm -f $(NAME)
	make -C $(FT_PRINTF) fclean


re: fclean all

.PHONY: all clean fclean re