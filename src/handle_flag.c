/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 21:27:14 by akyoshid          #+#    #+#             */
/*   Updated: 2024/12/28 21:27:27 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	handle_exit_flag(t_data *data)
{
	ft_printf("===============================\n");
	ft_printf("||          \033[1;32mGOTCHA!\033[0m          ||\n");
	ft_printf("||    \033[1;32mSuicune was caught!\033[0m    ||\n");
	ft_printf("===============================\n");
	mlx_loop_end(data->mlx);
}

void	handle_game_over_flag(t_data *data)
{
	ft_printf("===============================\n");
	ft_printf("||         \033[1;31mGAME OVER\033[0m         ||\n");
	ft_printf("===============================\n");
	mlx_loop_end(data->mlx);
}