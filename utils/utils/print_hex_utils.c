/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 20:59:37 by mel-hami          #+#    #+#             */
/*   Updated: 2024/11/30 20:59:38 by mel-hami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	_print_hex_hash(t_flags *flag, char x, ssize_t nbr);
static void	_print_hex_precision(t_flags *flag, char x, ssize_t nbr);

void	print_hex_padding(t_flags *flag, char x, ssize_t nbr)
{
	if (!flag->left_justify && flag->zero)
	{
		_print_hex_hash(flag, x, nbr);
		if (ft_check_ifwrite_failed())
			return ;
	}
	if (flag->left_justify)
	{
		print_hex_hash_and_precision(flag, x, nbr);
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
			_print_hex_hash(flag, x, nbr);
			if (ft_check_ifwrite_failed())
				return ;
		}
		_print_hex_precision(flag, x, nbr);
	}
}

void	print_hex_hash_and_precision(t_flags *flag, char x, ssize_t nbr)
{
	_print_hex_hash(flag, x, nbr);
	if (ft_check_ifwrite_failed())
		return ;
	_print_hex_precision(flag, x, nbr);
}

static void	_print_hex_hash(t_flags *flag, char x, ssize_t nbr)
{
	if (nbr != 0)
	{
		if (x == 'x')
		{
			if (flag->hash)
				ft_putstr_fd("0x", FD);
		}
		else
		{
			if (flag->hash)
				ft_putstr_fd("0X", FD);
		}
	}
}

static void	_print_hex_precision(t_flags *flag, char x, ssize_t nbr)
{
	ft_putlchar('0', flag->precision_value);
	if (ft_check_ifwrite_failed())
		return ;
	if (nbr != 0 || (nbr == 0 && !flag->precision))
	{
		if (x == 'x')
			ft_putnbr_base_fd(nbr, LOW_HEX_BASE, FD);
		else
			ft_putnbr_base_fd(nbr, UP_HEX_BASE, FD);
	}
}
