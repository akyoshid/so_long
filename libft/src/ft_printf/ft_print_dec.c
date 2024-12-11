/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 05:23:06 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/19 17:57:22 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

void	ft_print_signed_dec(int num, int *const cp)
{
	char	remainder;

	if (num == INT_MIN)
	{
		ft_print_str("-2147483648", cp);
		return ;
	}
	if (num < 0)
	{
		ft_print_char('-', cp);
		if (*cp == -1)
			return ;
		num *= -1;
	}
	remainder = num % 10 + '0';
	if (num / 10 > 0)
		ft_print_signed_dec(num / 10, cp);
	if (*cp != -1)
		ft_print_char(remainder, cp);
}

void	ft_print_unsigned_dec(unsigned int num, int *const cp)
{
	char	remainder;

	remainder = num % 10 + '0';
	if (num / 10 > 0)
		ft_print_unsigned_dec(num / 10, cp);
	if (*cp != -1)
		ft_print_char(remainder, cp);
}
