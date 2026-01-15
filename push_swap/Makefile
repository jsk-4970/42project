# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::   #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/26 00:00:00 by jyamada           #+#    #+#              #
#    Updated: 2026/01/15 12:44:16 by jyamada          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

# Compiler
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

# Directories
SRCDIR		= src
INCDIR		= include
OBJDIR		= obj

# Source files
SRCS		= main.c \
			  $(SRCDIR)/parse.c \
			  $(SRCDIR)/sort.c \
			  $(SRCDIR)/operation.c \
			  $(SRCDIR)/utils.c

# Object files
OBJS		= $(SRCS:%.c=$(OBJDIR)/%.o)

# Header
HEADER		= $(INCDIR)/push_swap.h

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJDIR)/%.o: %.c $(HEADER)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
