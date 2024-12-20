#include "libft.h"

void	ft_putaddress_fd(uintptr_t nbr, int fd)
{
	const char *base = hex_base;

	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr *= -1;
	}
	if (nbr < 16)
	{
		ft_putchar_fd(base[nbr], fd);
	}
	else
	{
		ft_putaddress_fd(nbr / 16, fd);
		ft_putchar_fd(base[nbr % 16], fd);
	}
}