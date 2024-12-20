/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 20:06:21 by mel-hami          #+#    #+#             */
/*   Updated: 2024/11/29 20:06:22 by mel-hami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs.h"

void	ft_print_char(t_flags *flag, char c)
{
	ft_output_length_cntl(1);
	if (flag->total_width > 1)
	{
		ft_output_length_cntl(--flag->total_width);
		if (flag->left_justify)
		{
			ft_putchar_fd(c, FD);
			if (ft_check_ifwrite_failed())
				return ;
		}
		ft_putl_zero_or_space(flag->zero, flag->total_width);
		if (ft_check_ifwrite_failed())
			return ;
		if (!flag->left_justify)
			ft_putchar_fd(c, FD);
	}
	else
		ft_putchar_fd(c, FD);
}
