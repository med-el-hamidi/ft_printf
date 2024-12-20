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

static void	_ft_print_ptr_precision(t_flags *flag, uintptr_t nbr);

void	print_ptr_padding(t_flags *flag, uintptr_t nbr)
{
	if (!flag->left_justify && flag->zero)
	{
		ft_putstr_fd("0x", FD);
		if (ft_check_ifwrite_failed())
			return ;
	}
	if (flag->left_justify)
	{
		print_ptr_hash_and_precision(flag, nbr);
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
			ft_putstr_fd("0x", FD);
			if (ft_check_ifwrite_failed())
				return ;
		}
		_ft_print_ptr_precision(flag, nbr);
	}
}

void	print_ptr_hash_and_precision(t_flags *flag, uintptr_t nbr)
{
	ft_putstr_fd("0x", FD);
	if (ft_check_ifwrite_failed())
		return ;
	_ft_print_ptr_precision(flag, nbr);
}

static void	_ft_print_ptr_precision(t_flags *flag, uintptr_t nbr)
{
	ft_putlchar('0', flag->precision_value);
	if (ft_check_ifwrite_failed())
		return ;
	if (nbr != 0 || (nbr == 0 && !flag->precision))
		ft_putptr_fd(nbr, FD);
}
