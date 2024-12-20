/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srcs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 20:28:12 by mel-hami          #+#    #+#             */
/*   Updated: 2024/11/29 20:28:14 by mel-hami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRCS_H
# define SRCS_H
# include <stdarg.h>
# include "../utils/utils.h"

void	ft_handle_flags_and_digits(char **str, t_flags *flag);
void	ft_print_char(t_flags *flag, char c);
void	ft_print_decimal(t_flags *flag, ssize_t nbr);
void	ft_print_hex(t_flags *flag, char x, ssize_t nbr);
void	ft_print_ptr(t_flags *flag, uintptr_t format_address);
void	ft_print_string(t_flags *flag, char *str);
#endif
