# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: teppei <teppei@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/23 12:46:40 by teppei            #+#    #+#              #
#    Updated: 2021/06/18 07:46:33 by teppei           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g
SRCD		=	srcs
SRCS		=	$(SRCD)/push_swap.c \
				$(SRCD)/ps_init_ps.c \
				$(SRCD)/ps_puterror.c \
				$(SRCD)/ps_free_ps.c \
				$(SRCD)/ps_dlst_clear.c \
				$(SRCD)/ps_init_dlst.c \
				$(SRCD)/ps_presort.c \
				$(SRCD)/ps_set_a.c \
				$(SRCD)/ps_dlst_addback.c \
				$(SRCD)/ps_sorted.c \
				$(SRCD)/ps_less_seven.c \
				$(SRCD)/ps_skip_check.c \
				$(SRCD)/ps_ans_update.c \
				$(SRCD)/ps_change_dlst.c \
				$(SRCD)/ps_commands.c \
				$(SRCD)/ps_double_commands.c \
				$(SRCD)/ps_update_ans_dlst.c \
				$(SRCD)/ps_cmds_shorten.c \
				
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
	$(CC) -o $(NAME) $(OBJS) $(LINK) $(LIBS)
%.o: %.c $(HEAD)
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS) */*.gch
	rm -rf *.dSYM
fclean: clean
	rm -f $(NAME)
	rm -f libs/*.a
alclean: fclean
	make fclean -C libft

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
