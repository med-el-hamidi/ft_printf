#include "utils.h"

int	is_in_set(char c, char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

void	update_output_length_by_precision(int *length, t_flags *flag)
{
	if (flag->precision_value >= *length)
	{
		flag->precision_value -= *length;
		*length += flag->precision_value;
	}
	else
		flag->precision_value = 0;
}

void	update_output_length_by_0(int *length, t_flags *flag, ssize_t nbr)
{
	if (nbr == 0 && flag->precision)
		*length = 0;
}

void	ft_putlchar(char c, int length)
{
	if (length <= 0)
		return ;
	while (length--)
		ft_putchar_fd(c, FD);
}

void	ft_putl_zero_or_space(int zero, int length)
{
	if (zero)
		ft_putlchar('0', length);
	else
		ft_putlchar(' ', length);
}
