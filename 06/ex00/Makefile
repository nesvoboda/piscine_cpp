# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/08 14:05:19 by ashishae          #+#    #+#              #
#    Updated: 2020/10/03 20:54:53 by ashishae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = convert
CFLAGS = -Wall -Wextra -Werror

all:		$(NAME)

.c.o:
			clang++ $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
			clang++ $(OBJS) $(CFLAGS) -o $(NAME)

clean:
			rm -f $(OBJS)


fclean:		clean
			rm -f $(NAME)

re:			fclean all

