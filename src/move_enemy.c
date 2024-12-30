/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 09:07:28 by akyoshid          #+#    #+#             */
/*   Updated: 2024/12/30 09:44:38 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	move_enemy_core(t_data *data, int index_code)
{
	if (index_code == INDEX_W)
	{
		data->map_data.map[data->map_data.r_y][data->map_data.r_x] = '0';
		data->map_data.r_y--;
		data->map_data.map[data->map_data.r_y][data->map_data.r_x] = 'R';
	}
	else if (index_code == INDEX_A)
	{
		data->map_data.map[data->map_data.r_y][data->map_data.r_x] = '0';
		data->map_data.r_x--;
		data->map_data.map[data->map_data.r_y][data->map_data.r_x] = 'R';
	}
	else if (index_code == INDEX_S)
	{
		data->map_data.map[data->map_data.r_y][data->map_data.r_x] = '0';
		data->map_data.r_y++;
		data->map_data.map[data->map_data.r_y][data->map_data.r_x] = 'R';
	}
	else if (index_code == INDEX_D)
	{
		data->map_data.map[data->map_data.r_y][data->map_data.r_x] = '0';
		data->map_data.r_x++;
		data->map_data.map[data->map_data.r_y][data->map_data.r_x] = 'R';
	}
}

void	move_enemy(t_data *data)
{
	char	dst_tile[4];
	int		tile_count;
	int		rand;

	if (data->loop_count == 0
		|| data->map_data.map[data->map_data.r_y][data->map_data.r_x] != 'R')
		return ;
	set_enemy_dst_tile(data, &dst_tile);
	if (dst_tile[INDEX_W] == 'P' || dst_tile[INDEX_A] == 'P'
		|| dst_tile[INDEX_S] == 'P' || dst_tile[INDEX_D] == 'P')
	{
		eliminate_player(data, dst_tile);
		return ;
	}
	tile_count = count_enemy_walkable_tile(dst_tile);
	rand = ft_rand_256();
	if (rand < 0)
		proc_rand_err(data, rand);
	choose_enemy_dst_tile(data, dst_tile, 0, rand % tile_count);
}
