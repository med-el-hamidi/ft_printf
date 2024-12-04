/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 20:20:00 by mel-hami          #+#    #+#             */
/*   Updated: 2024/12/04 19:37:58 by mel-hami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs.h"

void	ft_print_ptr(t_flags *flag, uintptr_t format_address)
{
	int	length;

	length = ft_ptrlen(format_address);
	update_output_length_by_0(&length, flag, format_address);
	update_output_length_by_precision(&length, flag);
	length += 2;
	ft_output_length_cntl(length);
	if (flag->total_width > length)
	{
		flag->total_width -= length;
		ft_output_length_cntl(flag->total_width);
		print_ptr_padding(flag, format_address);
	}
	else
		print_ptr_hash_and_precision(flag, format_address);
}
