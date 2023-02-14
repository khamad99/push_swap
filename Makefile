# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 14:57:31 by kalshaer          #+#    #+#              #
#    Updated: 2023/02/14 14:32:04 by kalshaer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT	=	./libft/libft.a

NAME	=	push_swap

NAME_B	=	checker

SRCS	=	push_swap_main.c \
			error.c \
			push_swap_utils.c \
			intiate.c \
			push.c \
			r_rotate.c \
			rotate.c \
			swap.c \
			sort.c \
			sort23.c \
			sort50.c \
			sortmore50.c \
			freearg.c \
			sort_utils.c \

SRCS_B	=	checker_error.c \
			checker_push_swap_main.c \
			checker_push_swap_utils.c \
			checker_intiate.c \
			checker_push.c \
			checker_r_rotate.c \
			checker_rotate.c \
			checker_swap.c \
			checker_freearg.c \

OBJS	=	$(SRCS:%.c=%.o)

OBJS_B	=	$(SRCS_B:%.c=%.o)

FLAGS	=	-Wall -Werror -Wextra

CC		=	cc

$(NAME):
	$(MAKE) -C ./libft
	$(CC) $(FLAGS) -c $(SRCS)  
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

all: $(NAME)

bonus:
	$(MAKE) -C ./libft
	$(CC) $(FLAGS) -c $(SRCS_B)  
	$(CC) $(FLAGS) $(OBJS_B) $(LIBFT) -o $(NAME_B)

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJS) $(OBJS_B)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME) $(NAME_B)
re: fclean all
