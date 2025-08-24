# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tao <tao@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/09 14:44:17 by tbraud            #+#    #+#              #
#    Updated: 2025/08/24 21:43:39 by tao              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= RPN

CXX			:= c++
CXXFLAGS	:= -Wall -Wextra -Werror -std=c++98

RM			:= rm -f

SRCS		:= main.cpp RPN.cpp\

OBJS		:= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@printf "✔️ $(NAME) compiled\n"

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	@printf "✔️ $(NAME) clean\n"

re: fclean all

.PHONY: all clean fclean re
