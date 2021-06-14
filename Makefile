# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: teppei <teppei@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/23 12:46:40 by teppei            #+#    #+#              #
#    Updated: 2021/06/14 14:39:51 by teppei           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g
SRCD		=	srcs
SRCS		=	$(SRCD)/push_swap.c
OBJS		=	$(SRCS:%.c=%.o)

HEAD		=	./incs/push_swap.h
INCS		=	-I./incs
LINK		=	-L./libs
LIBS		=	-lft

BONUS_NAME	= # your bonus target file

all: $(NAME)

$(NAME): $(OBJS)
	if [ ! -d libs ]; then mkdir libs; fi
	@make -C libft
	cp libft/libft.a ./libs
	# @make -C gnl
	# cp 42_utils/gnl/libgnl.a ./libs
	$(CC) -o $(NAME) $(OBJS) $(LINK) $(LIBS)
%.o: %.c $(HEAD)
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS) */*.gch
	rm -rf *.dSYM
fclean: clean
	rm -f $(NAME)
	rm -f libs/*.a
alclean: fclean bfclean
	make fclean -C libft
	# make fclean -C gnl

re: fclean all
cl: all clean
reall: alclean all

.PHONY: all clean fclean re cl alclean reall

# if you challenge bonus
bonus:
	make -C bonus
	cp bonus/$(BONUS_NAME) .

bclean:
	make clean -C bonus

bfclean:
	make fclean -C bonus
	rm $(BONUS_NAME)

.PHONY: bonus bclean bfclean
