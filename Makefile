# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 15:35:05 by gda_cruz          #+#    #+#              #
#    Updated: 2023/02/24 16:41:17 by gda_cruz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN		=	\033[0;32m
GREEN_BOLD	=	\033[1;32m
RED			=	\033[0;31m
YELLOW		=	\033[0;33m
BLUE		=	\033[0;34m
BLUE_BACK	=	\033[0;44m
RESET		=	\033[0m

NAME 		=	minishell

LIBFT_DIR		=	lib

SRC			=	srcs/main.c \

OBJ			=	$(SRC:srcs/%.c=$(OBJ_DIR)/%.o)
INC_DIR		=	inc
BUILD_DIR	=	./build
OBJ_DIR		=	$(BUILD_DIR)/objects

CC			=	gcc

CFLAGS		=	-g -Wall -Wextra -Werror
LIBFTFLAGS	=	-L$(LIBFT_DIR) -lft

all: $(NAME)

$(NAME):	$(OBJ)
	@echo "\n$(BLUE)Compiling libft...$(RESET)"
	@make -s -C $(LIBFT_DIR)
	@echo "$(YELLOW)[Libft successfully compiled!]\n$(RESET)"
	@echo "$(BLUE)Compiling minishell...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFTFLAGS) -o $(NAME)
	@printf "$(GREEN) ------------------------\n$(RESET)"
	@printf "$(GREEN_BOLD) [minishell ready to use]\n$(RESET)"
	@printf "$(GREEN) ------------------------\n$(RESET)"

$(OBJ_DIR)/%.o:	srcs/%.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) -c $(^) -o $(@)
	@printf "$(YELLOW)[OK]     "$@"$(RESET)\n"

.SILENT = $(OBJ)

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(OBJ_DIR)

clean:
	@make clean -s -C $(LIBFT_DIR)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make fclean -s -C $(LIBFT_DIR)
	@rm -rf build minishell
	@echo "$(RED)[All minishell files removed]$(RESET)"

re: fclean all

.PHONY: all clean fclean re
