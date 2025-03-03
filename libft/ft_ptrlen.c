#include "libft.h"

int	ft_ptrlen(uintptr_t n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n != 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}
