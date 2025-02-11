# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tao <tao@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/03 22:03:14 by tao               #+#    #+#              #
#    Updated: 2025/02/11 19:03:21 by tao              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= Harl_2.0

OBJ_DIR		:= obj

CXX			:= c++
CXXFLAGS	:= -Wextra -Wall -Werror -g -std=c++98

SRC			:= Harl.cpp main.cpp\

OBJ			:= $(SRC:%.c=$(OBJ_DIR)/%.o)

GREEN		:= \033[1;32m
NC			:= \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(OBJ) -o $(NAME)
	@printf "$(GREEN)✔️ $(NAME)$(NC) compiled\n"

$(OBJ_DIR)/%.o: $(SRC)
	@mkdir -p $(OBJ_DIR)
	@$(CXX) -o $@ -c $<
	@printf "$(GREEN)✔️ $(notdir $<)$(NC) compiled\n"

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)
	@printf "$(GREEN)✔️ $(NAME)$(NC) clean\n"

re: fclean all

.PHONY: all clean fclean re
