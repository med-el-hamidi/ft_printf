#include "libft.h"

static char	_check_base(char	*base, unsigned int len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (base[i] == '\0' || len == 1)
		return (0);
	while (base[i])
	{
		if (base[i] <= ' ' || base[i] > '~'
			|| base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j] && base[i] != base[j])
			j++;
		if (base[j])
			return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr_base_fd(ssize_t nbr, char *base, int fd)
{
	unsigned int	len;

	len = ft_strlen(base);
	if (!_check_base(base, len))
		return ;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr *= -1;
	}
	if (nbr < len)
		ft_putchar_fd(base[nbr], fd);
	else
	{
		ft_putnbr_base_fd(nbr / len, base, fd);
		ft_putchar_fd(base[nbr % len], fd);
	}
}
