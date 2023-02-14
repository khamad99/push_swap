# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 14:57:31 by kalshaer          #+#    #+#              #
#    Updated: 2023/02/14 09:27:45 by kalshaer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT	=	./libft/libft.a

NAME	=	push_swap

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


OBJS	=	$(SRCS:%.c=%.o)

FLAGS	=	-Wall -Werror -Wextra

CC		=	cc

$(NAME):
	$(MAKE) -C ./libft
	$(CC) $(FLAGS) -c $(SRCS)  
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

all: $(NAME)

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)
re: fclean all
