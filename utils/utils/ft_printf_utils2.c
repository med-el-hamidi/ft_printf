/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_length_cntl.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 20:04:55 by mel-hami          #+#    #+#             */
/*   Updated: 2024/11/30 20:51:22 by mel-hami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_output_length_cntl(int flag)
{
	static int	output_length;

	if (!flag)
		output_length = 0;
	else if (flag > 0)
		output_length += flag;
	else if (flag == -1)
		output_length = -1;
	return (output_length);
}

void	ft_check_bytes_written(int bytes_written)
{
	if (bytes_written == -1)
		ft_output_length_cntl(-1);
}

int	ft_check_ifwrite_failed(void)
{
	if (ft_output_length_cntl(-2) == -1)
		return (1);
	else
		return (0);
}
