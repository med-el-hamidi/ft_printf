/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 20:54:42 by mel-hami          #+#    #+#             */
/*   Updated: 2024/11/30 20:54:44 by mel-hami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# define FD 1
# include "../libft/libft.h"
# define UP_HEX_BASE "0123456789ABCDEF"
# define DEC_BASE "0123456789"

typedef struct s_flags
{
	int	space;
	int	hash;
	int	plus;
	int	left_justify;
	int	zero;
	int	precision;
	int	precision_value;
	int	field_min_width;
}	t_flags;

int		ft_output_length_cntl(int flag);
void	ft_check_bytes_written(int bytes_written);
int		ft_check_ifwrite_failed(void);

int		is_in_set(char c, char *set);
void	update_output_length_by_precision(int *length, t_flags *flag);
void	update_output_length_by_0(int *length, t_flags *flag, ssize_t nbr);
void	ft_putlchar(char c, int length);
void	ft_putl_zero_or_space(int zero, int length);

void	print_decimal_padding(t_flags *flag, ssize_t nbr);
void	print_decimal_plus_and_precision(t_flags *flag, ssize_t nbr);

void	print_hex_padding(t_flags *flag, char x, ssize_t nbr);
void	print_hex_hash_and_precision(t_flags *flag, char x, ssize_t nbr);

void	print_ptr_padding(t_flags *flag, uintptr_t format_address);
void	print_ptr_hash_and_precision(t_flags *flag, uintptr_t format_address);
#endif
