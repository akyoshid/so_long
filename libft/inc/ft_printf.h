/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:24:02 by akyoshid          #+#    #+#             */
/*   Updated: 2024/08/29 05:27:50 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

void	ft_print_char(char const c, int *const cp);
void	ft_print_str(char const *str, int *const cp);
void	ft_print_signed_dec(int num, int *const cp);
void	ft_print_unsigned_dec(unsigned int num, int *const cp);
void	ft_print_hex_char(char const num, int is_upper, int *const cp);
void	ft_print_hex(unsigned long long num, int is_upper, int *const cp);
void	ft_print_ptr(void *ptr, int *const cp);
void	ft_print_varg(char const fmt, va_list *app, int *const cp);
int		ft_printf(const char *fmt, ...);

#endif
