/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 09:11:02 by akyoshid          #+#    #+#             */
/*   Updated: 2024/12/30 10:50:20 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	set_enemy_dst_tile(t_data *data, char (*dst_tile)[4])
{
	(*dst_tile)[INDEX_W]
		= data->map_data.map[data->map_data.r_y - 1][data->map_data.r_x];
	(*dst_tile)[INDEX_A]
		= data->map_data.map[data->map_data.r_y][data->map_data.r_x - 1];
	(*dst_tile)[INDEX_S]
		= data->map_data.map[data->map_data.r_y + 1][data->map_data.r_x];
	(*dst_tile)[INDEX_D]
		= data->map_data.map[data->map_data.r_y][data->map_data.r_x + 1];
}

void	eliminate_player(t_data *data, char *dst_tile)
{
	if (dst_tile[INDEX_W] == 'P')
		move_enemy_core(data, INDEX_W);
	else if (dst_tile[INDEX_A] == 'P')
		move_enemy_core(data, INDEX_A);
	else if (dst_tile[INDEX_S] == 'P')
		move_enemy_core(data, INDEX_S);
	else if (dst_tile[INDEX_D] == 'P')
		move_enemy_core(data, INDEX_D);
	data->game_over_flag = 1;
}

int	count_enemy_walkable_tile(char *dst_tile)
{
	int	count;

	count = 0;
	if (dst_tile[INDEX_W] == '0')
		count++;
	if (dst_tile[INDEX_A] == '0')
		count++;
	if (dst_tile[INDEX_S] == '0')
		count++;
	if (dst_tile[INDEX_D] == '0')
		count++;
	return (count);
}

void	choose_enemy_dst_tile(
		t_data *data, char *dst_tile, int count, int rand)
{
	if (dst_tile[INDEX_W] == '0')
	{
		if (rand == count)
			move_enemy_core(data, INDEX_W);
		count++;
	}
	if (dst_tile[INDEX_A] == '0')
	{
		if (rand == count)
			move_enemy_core(data, INDEX_A);
		count++;
	}
	if (dst_tile[INDEX_S] == '0')
	{
		if (rand == count)
			move_enemy_core(data, INDEX_S);
		count++;
	}
	if (dst_tile[INDEX_D] == '0')
	{
		if (rand == count)
			move_enemy_core(data, INDEX_D);
		count++;
	}
}
