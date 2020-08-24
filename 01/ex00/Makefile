# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/08 14:05:19 by ashishae          #+#    #+#              #
#    Updated: 2020/08/24 13:15:40 by ashishae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.cpp Pony.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = pony
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

.c.o:
			clang++ $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
			clang++ $(OBJS) $(CFLAGS) -o $(NAME)

clean:
			rm -f $(OBJS)


fclean:		clean
			rm -f $(NAME)

re: fclean all

