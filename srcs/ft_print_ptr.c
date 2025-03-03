#include "srcs.h"

void	ft_print_ptr(t_flags *flag, uintptr_t nbr)
{
	int	length;

	length = ft_ptrlen(nbr);
	update_output_length_by_0(&length, flag, nbr);
	update_output_length_by_precision(&length, flag);
	length += 2;
	ft_output_length_cntl(length);
	if (flag->field_min_width > length)
	{
		flag->field_min_width -= length;
		ft_output_length_cntl(flag->field_min_width);
		print_ptr_padding(flag, nbr);
	}
	else
		print_ptr_hash_and_precision(flag, nbr);
}
