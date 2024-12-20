/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_flags_and_digits.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 20:02:39 by mel-hami          #+#    #+#             */
/*   Updated: 2024/11/30 20:46:26 by mel-hami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs.h"

static void	handle_digit(char **str, t_flags *flag);
static void	handle_flag(char c, t_flags *flag);
static void	handle_dot(char **str, t_flags *flag);

void	ft_handle_flags_and_digits(char **str, t_flags *flag)
{
	while (++(*str) && (is_in_set(**str, " #+-0.") || ft_isdigit(**str)))
	{
		if (ft_isdigit(**str) && !is_in_set(**str, " #+-0."))
		{
			handle_digit(str, flag);
			continue ;
		}
		if (**str == '.')
			handle_dot(str, flag);
		else
			handle_flag(**str, flag);
	}
}

static void	handle_digit(char **str, t_flags *flag)
{
	int	value;

	value = ft_atoi(*str);
	if (flag->precision_value)
		flag->precision_value = value;
	else
		flag->total_width = value;
	*str += ft_nbrlen_base(value, 10) - 1;
}

static void	handle_flag(char c, t_flags *flag)
{
	if (c == ' ')
		flag->space = 1;
	else if (c == '#')
		flag->hash = 2;
	else if (c == '+')
		flag->plus = 1;
	else if (c == '-')
	{
		flag->left_justify = 1;
		flag->zero = 0;
	}
	else if (c == '0' && !flag->left_justify)
		flag->zero = 1;
}

static void	handle_dot(char **str, t_flags *flag)
{
	int	f;

	f = 0;
	flag->precision = 1;
	flag->precision_value = 1;
	while (is_in_set(*(*str + 1), " #+-0"))
	{
		if (is_in_set(*(*str + 1), " #+-"))
		{
			f = 1;
			handle_flag(*(*str + 1), flag);
			flag->precision_value = 0;
		}
		if (f && *(*str + 1) == '0')
			handle_flag(*(*str + 1), flag);
		(*str)++;
	}
	if (!ft_isdigit(*(*str + 1)) && !is_in_set(*(*str + 1), " #+-0."))
		flag->precision_value = 0;
}
