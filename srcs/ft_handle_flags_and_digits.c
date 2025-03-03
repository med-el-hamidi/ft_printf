#include "srcs.h"

static void	handle_digit(char **str, t_flags *flag);
static void	handle_flag(char c, t_flags *flag);
static void	handle_dot(char **str, t_flags *flag);
static void	_fix_flags(char c, t_flags *flag);

void	ft_handle_flags_and_digits(char **str, t_flags *flag)
{
	int	cont;

	cont = 0;
	while (++(*str) && (is_in_set(**str, " #+-0.") || ft_isdigit(**str)))
	{
		cont = 0;
		if (ft_isdigit(**str) && **str != '0')
		{
			handle_digit(str, flag);
			cont = 1;
		}
		if (!cont)
		{
			if (**str == '.')
				handle_dot(str, flag);
			else
				handle_flag(**str, flag);
		}
	}
	_fix_flags(**str, flag);
}

static void	handle_digit(char **str, t_flags *flag)
{
	int	value;

	value = ft_atoi(*str);
	if (flag->precision_value)
		flag->precision_value = value;
	else
		flag->field_min_width = value;
	*str += ft_nbrlen_base(value, 10) - 1;
}

static void	handle_flag(char c, t_flags *flag)
{
	if (c == ' ')
		flag->space = 1;
	else if (c == '#')
		flag->hash = 2;
	else if (c == '+')
		flag->plus = 1;
	else if (c == '-')
	{
		flag->left_justify = 1;
		flag->zero = 0;
	}
	else if (c == '0' && !flag->left_justify)
		flag->zero = 1;
}

static void	handle_dot(char **str, t_flags *flag)
{
	int	f;

	f = 0;
	flag->precision = 1;
	flag->precision_value = 1;
	while (is_in_set(*(*str + 1), " #+-0"))
	{
		if (is_in_set(*(*str + 1), " #+-"))
		{
			f = 1;
			handle_flag(*(*str + 1), flag);
			flag->precision_value = 0;
		}
		if (f && *(*str + 1) == '0')
			handle_flag(*(*str + 1), flag);
		(*str)++;
	}
	if (!ft_isdigit(*(*str + 1)) && *(*str + 1) != '.')
		flag->precision_value = 0;
}

static void	_fix_flags(char c, t_flags *flag)
{
	if (is_in_set(c, "pdiuxX") && flag->precision)
	{
		flag->zero = 0;
	}
	if (c == 'u')
	{
		flag->plus = 0;
		flag->space = 0;
	}
}
