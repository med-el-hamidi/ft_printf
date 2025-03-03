#include "srcs.h"

static void	_update_output_length_nbr(int *length, t_flags *flag, ssize_t nbr);

void	ft_print_decimal(t_flags *flag, ssize_t nbr)
{
	int	length;

	length = ft_nbrlen_base(nbr, 10);
	_update_output_length_nbr(&length, flag, nbr);
	update_output_length_by_precision(&length, flag);
	length += (flag->space + flag->plus);
	if (length > 0)
		ft_output_length_cntl(length);
	if (flag->field_min_width > length)
	{
		flag->field_min_width -= length;
		ft_output_length_cntl(flag->field_min_width);
		print_decimal_padding(flag, nbr);
	}
	else
		print_decimal_plus_and_precision(flag, nbr);
}

static void	_update_output_length_nbr(int *length, t_flags *flag, ssize_t nbr)
{
	if (nbr < 0)
	{
		flag->plus = 1;
		(*length)--;
	}
	update_output_length_by_0(length, flag, nbr);
	if (flag->space && !flag->plus)
		ft_putchar_fd(' ', FD);
	else if (flag->plus)
		flag->space = 0;
}
