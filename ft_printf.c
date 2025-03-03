#include "ft_printf.h"

static void	_ft_print_based_on_format(va_list args, t_flags *flag, char c);
static void	_ft_printf(va_list args, const char *str);

int	ft_printf(const char *str, ...)
{
	va_list	args;

	va_start(args, str);
	ft_output_length_cntl(0);
	_ft_printf(args, str);
	return (ft_output_length_cntl(-2));
}

static void	_ft_print_based_on_format(va_list args, t_flags *flag, char c)
{
	if (c == '%')
		ft_print_char(flag, c);
	else if (is_in_set(c, "cspdiuxX"))
	{
		if (c == 'c')
			ft_print_char(flag, va_arg(args, int));
		else if (c == 's')
			ft_print_string(flag, va_arg(args, char *));
		else if (c == 'p')
			ft_print_ptr(flag, (uintptr_t)va_arg(args, void *));
		else if (c == 'd' || c == 'i')
			ft_print_decimal(flag, va_arg(args, int));
		else if (c == 'u')
			ft_print_decimal(flag, va_arg(args, unsigned int));
		else if (c == 'x' || c == 'X')
			ft_print_hex(flag, c, va_arg(args, unsigned int));
	}
	else if (c)
		ft_print_char(flag, c);
}

static void	_ft_printf(va_list args, const char *str)
{
	char	*tmp;
	t_flags	flag;

	if (write(FD, NULL, 0) == -1)
	{
		//ft_putstr_fd("ERROR: STDOUT_FILENO is closed!\n", 2);
		ft_output_length_cntl(-1);
		return ;
	}
	tmp = (char *)str;
	while (*tmp)
	{
		if (*tmp == '%')
		{
			ft_bzero(&flag, sizeof(flag));
			ft_handle_flags_and_digits(&tmp, &flag);
			_ft_print_based_on_format(args, &flag, *tmp);
		}
		else
		{
			ft_putchar_fd(*tmp, FD);
			ft_output_length_cntl(1);
		}
		if (*tmp)
			tmp++;
	}
}
