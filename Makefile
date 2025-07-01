# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clouden <clouden@student.42madrid.com      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/30 16:32:06 by clouden           #+#    #+#              #
#    Updated: 2025/07/01 14:45:59 by clouden          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Complier and flags
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g3

# Name of the output static library
NAME	= libftprintf.a

# Source and object files
SRCS	= ft_printf.c
OBJS	= $(SRCS:.c=.o)

# Libft include
LIBFT_DIR 	= libft
LIBFT 		= $(LIBFT_DIR)/libft.a
INCLUDES 	= -I$(LIBFT_DIR)

# Test file
TEST_SRC = .test.c
TEST_OBJ = $(TEST_SRC:.c=.o)
TEST_BIN = test_printf

# Default rule
all: $(LIBFT) $(NAME)

# Rule to build the library from object files
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Rule to compile .c to .o
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Build libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Optional build test
test: $(TEST_OBJ) $(NAME) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $(TEST_BIN)

# Clean object files
clean:
	rm -f $(OBJS) $(TEST_OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

# Clean object files and library
fclean: clean
	rm -f $(NAME) $(TEST_BIN)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Rebuild
re: fclean all

.PHONY: all test clean fclean re
