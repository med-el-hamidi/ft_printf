/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 20:28:39 by mel-hami          #+#    #+#             */
/*   Updated: 2024/11/30 20:43:16 by mel-hami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	_ft_print_based_on_format(va_list args, t_flags *flag, char c);
static void	_ft_printf(va_list args, const char *str);
static void	_fix_flag_zero(t_flags *flag, char c);

int	ft_printf(const char *str, ...)
{
	va_list	args;

	va_start(args, str);
	ft_output_length_cntl(0);
	_ft_printf(args, str);
	va_end(args);
	return (ft_output_length_cntl(-2));
}

static void	_fix_flag_zero(t_flags *flag, char c)
{
	if (is_in_set(c, "pdiuxX") && flag->precision)
	{
		flag->zero = 0;
	}
}

static void	_ft_print_based_on_format(va_list args, t_flags *flag, char c)
{
	_fix_flag_zero(flag, c);
	if (c == '%')
		ft_print_char(flag, c);
	else if (is_in_set(c, "cspdiuxX"))
	{
		if (c == 'c')
			ft_print_char(flag, va_arg(args, int));
		else if (c == 's')
			ft_print_string(flag, va_arg(args, char *));
		else if (c == 'p')
			ft_print_ptr(flag, (uintptr_t)va_arg(args, void *));
		else if (c == 'd' || c == 'i')
			ft_print_decimal(flag, va_arg(args, int));
		else if (c == 'u')
		{
			flag->plus = 0;
			flag->space = 0;
			ft_print_decimal(flag, va_arg(args, unsigned int));
		}
		else if (c == 'x' || c == 'X')
			ft_print_hex(flag, c, va_arg(args, unsigned int));
	}
	else if (c)
		ft_print_char(flag, c);
}

static void	_ft_printf(va_list args, const char *str)
{
	char	*tmp;
	t_flags	flag;

	tmp = (char *)str;
	while (*tmp)
	{
		if (*tmp == '%')
		{
			ft_bzero(&flag, sizeof(flag));
			ft_handle_flags_and_digits(&tmp, &flag);
			_ft_print_based_on_format(args, &flag, *tmp);
			if (ft_check_ifwrite_failed())
				return ;
		}
		else
		{
			ft_putchar_fd(*tmp, FD);
			if (ft_check_ifwrite_failed())
				return ;
			ft_output_length_cntl(1);
		}
		if (*tmp)
			tmp++;
	}
}
