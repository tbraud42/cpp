# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tao <tao@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/09 14:44:17 by tbraud            #+#    #+#              #
#    Updated: 2024/10/04 23:05:32 by tao              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= PhoneBook

OBJ_DIR	:= obj

CC		:= c++
CFLAGS	:= -Wextra -Wall -Werror -std=c++98

SRC		:= PhoneBook.cpp Contact.cpp \

OBJ		:= $(SRC:%.c=$(OBJ_DIR)/%.o)

GREEN	:= \033[1;32m
NC		:= \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) && printf "$(GREEN)✔️ $(NAME)$(NC) compiled\n"

$(OBJ_DIR)/%.o: $(SRC)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $< && printf "$(GREEN)✔️ $(notdir $<)$(NC) compiled\n"

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re
