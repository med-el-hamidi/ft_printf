/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 21:01:57 by mel-hami          #+#    #+#             */
/*   Updated: 2024/11/30 21:01:59 by mel-hami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	_ft_print_ptr_precision(t_flags *flag, uintptr_t format_address);

void	print_ptr_padding(t_flags *flag, uintptr_t format_address)
{
	if (!flag->left_justify && flag->zero)
	{
		ft_putstr_fd("0x", FD);
		if (ft_check_ifwrite_failed())
			return ;
	}
	if (flag->left_justify)
	{
		print_ptr_hash_and_precision(flag, format_address);
		if (ft_check_ifwrite_failed())
			return ;
	}
	ft_putl_zero_or_space(flag->zero, flag->total_width);
	if (ft_check_ifwrite_failed())
		return ;
	if (!flag->left_justify)
	{
		if (!flag->zero)
		{
			ft_putstr_fd("0x", FD);
			if (ft_check_ifwrite_failed())
				return ;
		}
		_ft_print_ptr_precision(flag, format_address);
	}
}

void	print_ptr_hash_and_precision(t_flags *flag, uintptr_t format_address)
{
	ft_putstr_fd("0x", FD);
	if (ft_check_ifwrite_failed())
		return ;
	_ft_print_ptr_precision(flag, format_address);
}

static void	_ft_print_ptr_precision(t_flags *flag, uintptr_t format_address)
{
	ft_putlchar('0', flag->precision_value);
	if (ft_check_ifwrite_failed())
		return ;
	if (format_address != 0 || (format_address == 0 && !flag->precision))
		ft_putptr_fd(format_address, FD);
}
