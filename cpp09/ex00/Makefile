# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tao <tao@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/09 14:44:17 by tbraud            #+#    #+#              #
#    Updated: 2025/08/15 18:25:51 by tao              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= btc

CXX			:= c++
CXXFLAGS	:= -Wextra -Wall -Werror -g -std=c++98

SRC			:= main.cpp BitcoinExchange.cpp\

OBJ			:= $(SRC:%.c=%.o)

GREEN		:= \033[1;32m
NC			:= \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@printf "$(GREEN)✔️ $(NAME)$(NC) compiled\n"

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)
	@printf "$(GREEN)✔️ $(NAME)$(NC) clean\n"

re: fclean all

.PHONY: all clean fclean re
