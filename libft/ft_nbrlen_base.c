#include "libft.h"

int	ft_nbrlen_base(ssize_t n, unsigned int base)
{
	int	i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n != 0)
	{
		n /= base;
		i++;
	}
	return (i);
}
