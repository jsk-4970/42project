NAME = libftprintf.a
SRCS = ft_printf.c \
		ft_puts1.c \
		ft_puts2.c \
		ft_putchar.c \
		ft_putnbr.c \
		ft_putstr.c \
		ft_strlcpy.c \
		ft_strlen.c \

OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra
all: $(NAME)
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
%.o: %.c libft.h
	$(CC) $(FCLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean $(NAME)
.PHONY: all clean fclean re
