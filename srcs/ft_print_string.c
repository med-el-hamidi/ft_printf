/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 20:23:15 by mel-hami          #+#    #+#             */
/*   Updated: 2024/11/29 20:23:16 by mel-hami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs.h"

static void	_ft_putlstr(char *str, int length);
static void	_ft_print_str(t_flags *flag, char *str, int length);

void	ft_print_string(t_flags *flag, char *str)
{
	int	length;

	length = 6;
	if (str)
		length = (int)ft_strlen(str);
	if (flag->precision && flag->precision_value < length)
		length = flag->precision_value;
	if (str)
		_ft_print_str(flag, str, length);
	else
		_ft_print_str(flag, "(null)", length);
}

static void	_ft_putlstr(char *str, int length)
{
	if (length <= 0)
		return ;
	while (*str && length--)
	{
		ft_putchar_fd(*str++, FD);
		if (ft_check_ifwrite_failed())
			return ;
	}
}

static void	_ft_print_str(t_flags *flag, char *str, int length)
{
	if (length > 0)
		ft_output_length_cntl(length);
	if (flag->total_width > length)
	{
		flag->total_width -= length;
		ft_output_length_cntl(flag->total_width);
		if (flag->left_justify)
		{
			_ft_putlstr(str, length);
			if (ft_check_ifwrite_failed())
				return ;
			flag->zero = 0;
		}
		ft_putl_zero_or_space(flag->zero, flag->total_width);
		if (ft_check_ifwrite_failed())
			return ;
		if (!flag->left_justify)
			_ft_putlstr(str, length);
	}
	else
		_ft_putlstr(str, length);
}
