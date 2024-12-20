/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 20:57:24 by mel-hami          #+#    #+#             */
/*   Updated: 2024/11/30 20:57:26 by mel-hami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	_print_decimal_plus(t_flags *flag, ssize_t nbr);
static void	_print_decimal_precision(t_flags *flag, ssize_t nbr);

void	print_decimal_padding(t_flags *flag, ssize_t nbr)
{
	if (!flag->left_justify && flag->zero)
	{
		_print_decimal_plus(flag, nbr);
		if (ft_check_ifwrite_failed())
			return ;
	}
	if (flag->left_justify)
	{
		print_decimal_plus_and_precision(flag, nbr);
		if (ft_check_ifwrite_failed())
			return ;
	}
	ft_putl_zero_or_space(flag->zero, flag->field_min_width);
	if (ft_check_ifwrite_failed())
		return ;
	if (!flag->left_justify)
	{
		if (!flag->zero)
		{
			_print_decimal_plus(flag, nbr);
			if (ft_check_ifwrite_failed())
				return ;
		}
		_print_decimal_precision(flag, nbr);
	}
}

void	print_decimal_plus_and_precision(t_flags *flag, ssize_t nbr)
{
	_print_decimal_plus(flag, nbr);
	if (ft_check_ifwrite_failed())
		return ;
	_print_decimal_precision(flag, nbr);
}

static void	_print_decimal_plus(t_flags *flag, ssize_t nbr)
{
	if (flag->plus && nbr >= 0)
		ft_putchar_fd('+', FD);
	else if (nbr < 0)
		ft_putchar_fd('-', FD);
}

static void	_print_decimal_precision(t_flags *flag, ssize_t nbr)
{
	ft_putlchar('0', flag->precision_value);
	if (ft_check_ifwrite_failed())
		return ;
	if (nbr > 0 || (nbr == 0 && !flag->precision))
		ft_putnbr_base_fd(nbr, DEC_BASE, FD);
	else if (nbr < 0)
		ft_putnbr_base_fd((nbr * -1), DEC_BASE, FD);
}
