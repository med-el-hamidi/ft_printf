#include "srcs.h"

int	ft_output_length_cntl(int flag)
{
	static int	output_length;

	if (!flag)
		output_length = 0;
	else if (flag > 0)
		output_length += flag;
	else if (flag == -1)
		output_length = -1;
	return (output_length);
}
