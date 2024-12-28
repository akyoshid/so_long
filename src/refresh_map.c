/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:23:03 by akyoshid          #+#    #+#             */
/*   Updated: 2024/12/28 15:23:48 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	set_current_and_dst_tile(t_data *data, char **current, char **dst)
{
	*current = &data->map_data.map[data->map_data.p_y][data->map_data.p_x];
	*dst = NULL;
	if (data->key == KEY_W
		|| (data->key == KEY_X
			&& data->map_data.map[data->map_data.p_y - 1][data->map_data.p_x]
		== 'R'))
		*dst = &data->map_data.map[data->map_data.p_y - 1][data->map_data.p_x];
	else if (data->key == KEY_A
		|| (data->key == KEY_X
			&& data->map_data.map[data->map_data.p_y][data->map_data.p_x - 1]
		== 'R'))
		*dst = &data->map_data.map[data->map_data.p_y][data->map_data.p_x - 1];
	else if (data->key == KEY_S
		|| (data->key == KEY_X
			&& data->map_data.map[data->map_data.p_y + 1][data->map_data.p_x]
		== 'R'))
		*dst = &data->map_data.map[data->map_data.p_y + 1][data->map_data.p_x];
	else if (data->key == KEY_D
		|| (data->key == KEY_X
			&& data->map_data.map[data->map_data.p_y][data->map_data.p_x + 1]
		== 'R'))
		*dst = &data->map_data.map[data->map_data.p_y][data->map_data.p_x + 1];
}

int	check_tile_walkable(t_data *data, char *dst_tile)
{
	if (*dst_tile == '0' || *dst_tile == 'C' || *dst_tile == 'L')
		return (1);
	else if (data->map_data.c_collected == data->map_data.c_count
		&& *dst_tile == 'E')
		return (1);
	return (0);
}

void	change_tile(t_data *data, char *current_tile, char *dst_tile)
{
	if (data->key != KEY_X)
	{
		if (*dst_tile == 'C')
			data->map_data.c_collected++;
		else if (*dst_tile == 'E')
			data->exit_flag = 1;
		*dst_tile = 'P';
		*current_tile = '0';
	}
	else
		*dst_tile = 'L';
}

void	change_player_pos(t_data *data)
{
	if (data->key == KEY_W)
		data->map_data.p_y--;
	if (data->key == KEY_A)
		data->map_data.p_x--;
	if (data->key == KEY_S)
		data->map_data.p_y++;
	if (data->key == KEY_D)
		data->map_data.p_x++;
}

void	refresh_map(t_data *data)
{
	char	*current_tile;
	char	*dst_tile;

	set_current_and_dst_tile(data, &current_tile, &dst_tile);
	if (data->key != KEY_X && check_tile_walkable(data, dst_tile) == 1)
	{
		change_tile(data, current_tile, dst_tile);
		change_player_pos(data);
		data->move_count++;
		ft_printf("number of movements: %u\n", data->move_count);
	}
	else if (data->key == KEY_X && dst_tile != NULL)
		change_tile(data, current_tile, dst_tile);
	data->key = 0;
}
