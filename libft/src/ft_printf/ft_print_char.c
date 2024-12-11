/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 05:21:51 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/19 17:57:18 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

void	ft_print_char(char const c, int *const cp)
{
	if ((write(1, &c, 1)) == -1)
		*cp = -1;
	else
		(*cp)++;
}

void	ft_print_str(char const *str, int *const cp)
{
	if (str == NULL)
	{
		ft_print_str("(null)", cp);
		return ;
	}
	while (*str != '\0')
	{
		ft_print_char(*str, cp);
		if (*cp == -1)
			return ;
		str++;
	}
}
