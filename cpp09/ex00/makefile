# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/06 16:36:58 by mdomnik           #+#    #+#              #
#    Updated: 2025/06/02 21:45:25 by mdomnik          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Text formatting
RESET  = \033[0m
GREEN  = \033[1;32m
MAGENTA = \033[1;35m
CYAN   = \033[1;36m

# Symbols
CHECK_MARK = $(MAGENTA)✔$(RESET)
ROCKET     = 🚀

# Project variables
NAME = btc
SRC = src/main.cpp src/BitcoinExchange.cpp
OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.cpp=.o)))
COMPILER = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror

# Build all
all: $(NAME)

# Build executable
$(NAME): $(OBJ)
	@echo "$(MAGENTA)Building $(NAME)...$(RESET)"
	@$(COMPILER) $(FLAGS) $^ -o $@
	@echo "$(MAGENTA)Linked successfully$(RESET) $(CHECK_MARK)"
	@echo "$(GREEN)Build completed!$(RESET) $(ROCKET)"

# Compile object files
$(OBJ_DIR)/%.o: src/%.cpp | $(OBJ_DIR)
	@echo "$(CYAN)Compiling $<$(RESET)"
	@$(COMPILER) $(FLAGS) -c $< -o $@

# Create object directory
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Clean object files
clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(MAGENTA)Object files removed!$(RESET)"

# Clean everything
fclean: clean
	@rm -f $(NAME)
	@echo "$(MAGENTA)Executable removed!$(RESET)"

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re
