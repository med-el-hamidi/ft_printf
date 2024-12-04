/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 20:09:38 by mel-hami          #+#    #+#             */
/*   Updated: 2024/11/30 20:47:12 by mel-hami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs.h"

static void	_update_output_length_nbr(int *length, t_flags *flag, ssize_t nbr);

void	ft_print_decimal(t_flags *flag, ssize_t nbr)
{
	int	length;

	length = ft_nbrlen_base(nbr, 10);
	_update_output_length_nbr(&length, flag, nbr);
	if (ft_check_ifwrite_failed())
		return ;
	update_output_length_by_precision(&length, flag);
	length += (flag->space + flag->plus);
	if (length > 0)
		ft_output_length_cntl(length);
	if (flag->total_width > length)
	{
		flag->total_width -= length;
		ft_output_length_cntl(flag->total_width);
		print_decimal_padding(flag, nbr);
	}
	else
		print_decimal_plus_and_precision(flag, nbr);
}

static void	_update_output_length_nbr(int *length, t_flags *flag, ssize_t nbr)
{
	if (nbr < 0)
	{
		flag->plus = 1;
		(*length)--;
	}
	update_output_length_by_0(length, flag, nbr);
	if (flag->space && !flag->plus)
		ft_putchar_fd(' ', FD);
	else if (flag->plus)
		flag->space = 0;
}
