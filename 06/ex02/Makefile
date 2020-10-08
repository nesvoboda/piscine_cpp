# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/08 14:05:19 by ashishae          #+#    #+#              #
#    Updated: 2020/10/08 14:58:37 by ashishae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.cpp A.cpp B.cpp C.cpp Base.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = guess
CXXFLAGS = -Wall -Wextra -Werror -D DEBUG=1
CXX = clang++

all:		$(NAME)

$(NAME):	$(OBJS)
			clang++ $(OBJS) $(CXXFLAGS) -o $(NAME)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		clean fclean re all
