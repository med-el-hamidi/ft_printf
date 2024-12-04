NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

PATH_LIBFT = libft/
PATH_SRCS = srcs/
PATH_UTILS = utils/

SRCS_LIBFT = libft/ft_atoi.c libft/ft_bzero.c libft/ft_isdigit.c \
			libft/ft_nbrlen_base.c libft/ft_ptrlen.c libft/ft_putchar_fd.c \
			libft/ft_putnbr_base_fd.c libft/ft_putptr_fd.c libft/ft_putstr_fd.c \
			libft/ft_strlen.c

SRCS_SRCS = srcs/ft_handle_flags_and_digits.c srcs/ft_print_char.c srcs/ft_print_decimal.c \
			srcs/ft_print_hex.c srcs/ft_print_ptr.c srcs/ft_print_string.c

SRCS_UTILS = utils/ft_printf_utils1.c utils/ft_printf_utils2.c utils/print_decimal_utils.c \
			utils/print_hex_utils.c utils/print_ptr_utils.c

HEADERS = $(PATH_LIBFT)libft.h $(PATH_UTILS)utils.h $(PATH_SRCS)srcs.h ft_printf.h

SRCS = $(SRCS_LIBFT) $(SRCS_UTILS) $(SRCS_SRCS) ft_printf.c
OBJS = $(SRCS:.c=.o)

RM = rm -f

$(NAME): $(OBJS)
	ar -rcs $@ $^

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

all:$(NAME)

bonus: all

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all


.PHONY: clean