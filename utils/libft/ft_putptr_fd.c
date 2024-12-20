/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 19:53:56 by mel-hami          #+#    #+#             */
/*   Updated: 2024/11/29 19:58:33 by mel-hami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putptr_fd(uintptr_t nbr, int fd)
{
	const char	*base;

	base = LOW_HEX_BASE;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		if (ft_check_ifwrite_failed())
			return ;
		nbr *= -1;
	}
	if (nbr < 16)
		ft_putchar_fd(base[nbr], fd);
	else
	{
		ft_putptr_fd(nbr / 16, fd);
		if (ft_check_ifwrite_failed())
			return ;
		ft_putchar_fd(base[nbr % 16], fd);
	}
}
