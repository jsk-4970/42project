NAME		= push_swap

# Compiler
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

# Directories
SRCDIR		= src
INCDIR		= include
OBJDIR		= obj
#LIBFTDIR	= libft

# Libft
#LIBFT		= $(LIBFTDIR)/libft.a

# Source files
SRCS		= $(SRCDIR)/main.c \
			  $(SRCDIR)/parse.c \
			  $(SRCDIR)/sort.c \
			  $(SRCDIR)/sort_small.c \
			  $(SRCDIR)/stack.c \
			  $(SRCDIR)/operation1.c \
			  $(SRCDIR)/operation2.c \
			  $(SRCDIR)/operation3.c \
			  $(SRCDIR)/utils.c \
			  $(SRCDIR)/ft_split.c \
			  $(SRCDIR)/ft_strlen.c \
			  $(SRCDIR)/ft_substr.c \
			  $(SRCDIR)/free.c \
			  $(SRCDIR)/ft_strdup.c

# Object files
OBJS		= $(SRCS:%.c=$(OBJDIR)/%.o)

# Header
HEADER		= $(INCDIR)/push_swap.h

# Rules
all: $(NAME)

#$(LIBFT):
#	$(MAKE) -C $(LIBFTDIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

$(OBJDIR)/%.o: %.c $(HEADER)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
