/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:26:32 by akyoshid          #+#    #+#             */
/*   Updated: 2024/12/28 15:27:03 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	loop_hook(t_data *data)
{
	if (data->loop_count % (256 * 2) == 0)
	{
		if (data->loop_count % (256 * 16) == 0)
			data->suicune_count++;
		if (data->loop_count % (256 * 256) == 0)
		{
			// move_enemy(data);
			data->loop_count = 0;
		}
		refresh_display(data);
		if (data->exit_flag == 1)
		{
			ft_printf("===============================\n");
			ft_printf("||          \033[1;32mGOTCHA!\033[0m          ||\n");
			ft_printf("||    \033[1;32mSuicune was caught!\033[0m    ||\n");
			ft_printf("================================\n");
			mlx_loop_end(data->mlx);
		}
	}
	data->loop_count++;
	return (0);
}
