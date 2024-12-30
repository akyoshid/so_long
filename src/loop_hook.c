/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:26:32 by akyoshid          #+#    #+#             */
/*   Updated: 2024/12/30 11:12:07 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	loop_hook(t_data *data)
{
	if (data->loop_count % (256 * 2) == 0)
	{
		if (data->loop_count % (256 * 16) == 0)
			data->suicune_count++;
		if (data->loop_count % (256 * 32) == 0)
		{
			if (data->exit_flag == 2 || data->game_over_flag == 2)
				mlx_loop_end(data->mlx);
		}
		if (data->loop_count % (256 * 256) == 0)
		{
			move_enemy(data);
			data->loop_count = 0;
		}
		if (data->exit_flag == 2 || data->game_over_flag == 2)
			data->key = 0;
		refresh_display(data);
		if (data->exit_flag == 1)
			handle_exit_flag(data);
		if (data->game_over_flag == 1)
			handle_game_over_flag(data);
	}
	data->loop_count++;
	return (0);
}
