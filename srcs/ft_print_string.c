#include "srcs.h"

static void	_ft_putlstr(char *str, int length);
static void	_ft_print_str(t_flags *flag, char *str, int length);

void	ft_print_string(t_flags *flag, char *str)
{
	int	length;

	length = 6;
	if (str)
		length = (int)ft_strlen(str);
	if (flag->precision && flag->precision_value < length)
		length = flag->precision_value;
	if (str)
		_ft_print_str(flag, str, length);
	else
		_ft_print_str(flag, "(null)", length);
}

static void	_ft_putlstr(char *str, int length)
{
	if (length <= 0)
		return ;
	while (*str && length--)
		ft_putchar_fd(*str++, FD);
}

static void	_ft_print_str(t_flags *flag, char *str, int length)
{
	if (length > 0)
		ft_output_length_cntl(length);
	if (flag->field_min_width > length)
	{
		flag->field_min_width -= length;
		ft_output_length_cntl(flag->field_min_width);
		if (flag->left_justify)
			_ft_putlstr(str, length);
		ft_putl_zero_or_space(flag->zero, flag->field_min_width);
		if (!flag->left_justify)
			_ft_putlstr(str, length);
	}
	else
		_ft_putlstr(str, length);
}
