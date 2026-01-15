# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/26 00:00:00 by jyamada           #+#    #+#              #
#    Updated: 2025/12/26 00:00:00 by jyamada          ###   ########.fr        #
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
LIBFTDIR	= libft

# Libft
LIBFT		= $(LIBFTDIR)/libft.a

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

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) -L$(LIBFTDIR) -lft

$(OBJDIR)/%.o: %.c $(HEADER)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBFTDIR) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFTDIR) clean
	rm -rf $(OBJDIR)

fclean: clean
	$(MAKE) -C $(LIBFTDIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
