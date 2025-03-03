#include "srcs.h"

void	ft_print_char(t_flags *flag, char c)
{
	ft_output_length_cntl(1);
	if (flag->field_min_width > 1)
	{
		ft_output_length_cntl(--flag->field_min_width);
		if (flag->left_justify)
			ft_putchar_fd(c, FD);
		ft_putl_zero_or_space(flag->zero, flag->field_min_width);
		if (!flag->left_justify)
			ft_putchar_fd(c, FD);
	}
	else
		ft_putchar_fd(c, FD);
}
