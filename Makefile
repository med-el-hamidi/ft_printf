NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

PATH_LIBFT = ./libft/
SRCS_LIBFT = $(addprefix $(PATH_LIBFT), ft_isalpha.c ft_isdigit.c ft_strncmp.c ft_atoi.c ft_bzero.c ft_strlcpy.c ft_strlen.c ft_ptrlen.c ft_nbrlen_base.c ft_putptr_fd.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_base_fd.c ft_putendl_fd.c)

HEADERS = $(PATH_LIBFT)libft.h ft_printf.h

SRCS = $(SRCS_LIBFT) ft_printf.c
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