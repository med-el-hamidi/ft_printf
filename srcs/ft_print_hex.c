#include "srcs.h"

void	ft_print_hex(t_flags *flag, char x, ssize_t nbr)
{
	int	length;

	length = ft_nbrlen_base(nbr, 16);
	update_output_length_by_0(&length, flag, nbr);
	update_output_length_by_precision(&length, flag);
	if (nbr != 0)
		length += flag->hash;
	if (length > 0)
		ft_output_length_cntl(length);
	if (flag->field_min_width > length)
	{
		flag->field_min_width -= length;
		ft_output_length_cntl(flag->field_min_width);
		print_hex_padding(flag, x, nbr);
	}
	else
		print_hex_hash_and_precision(flag, x, nbr);
}
