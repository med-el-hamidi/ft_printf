/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 20:24:49 by mel-hami          #+#    #+#             */
/*   Updated: 2024/11/29 20:24:51 by mel-hami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	is_in_set(char c, char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

void	update_output_length_by_precision(int *length, t_flags *flag)
{
	if (flag->precision_value >= *length)
	{
		flag->precision_value -= *length;
		*length += flag->precision_value;
	}
	else
		flag->precision_value = 0;
}

void	update_output_length_by_0(int *length, t_flags *flag, ssize_t nbr)
{
	if (nbr == 0 && flag->precision)
		*length = 0;
}

void	ft_putlchar(char c, int length)
{
	if (length <= 0)
		return ;
	while (length--)
	{
		ft_putchar_fd(c, FD);
		if (ft_check_ifwrite_failed())
			return ;
	}
}

void	ft_putl_zero_or_space(int zero, int length)
{
	if (zero)
		ft_putlchar('0', length);
	else
		ft_putlchar(' ', length);
}
