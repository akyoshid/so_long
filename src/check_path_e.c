/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_e.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:45:52 by akyoshid          #+#    #+#             */
/*   Updated: 2025/01/02 19:53:24 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	set_enemy_pos(t_map *map_data, int x, int y)
{
	map_data->r_x = x;
	map_data->r_y = y;
}

void	check_enemy_pos(t_map *map_data, char **map_cpy, int x, int y)
{
	if (map_data->map[y - 1][x] != 'C' && map_cpy[y - 1][x] == 'v')
		set_enemy_pos(map_data, x, y - 1);
	else if (map_data->map[y][x - 1] != 'C' && map_cpy[y][x - 1] == 'v')
		set_enemy_pos(map_data, x - 1, y);
	else if (map_data->map[y + 1][x] != 'C' && map_cpy[y + 1][x] == 'v')
		set_enemy_pos(map_data, x, y + 1);
	else if (map_data->map[y][x + 1] != 'C' && map_cpy[y][x + 1] == 'v')
		set_enemy_pos(map_data, x + 1, y);
	else if (map_data->map[y - 1][x] != 'C' && map_cpy[y - 1][x] == 'V')
		set_enemy_pos(map_data, x, y - 1);
	else if (map_data->map[y][x - 1] != 'C' && map_cpy[y][x - 1] == 'V')
		set_enemy_pos(map_data, x - 1, y);
	else if (map_data->map[y + 1][x] != 'C' && map_cpy[y + 1][x] == 'V')
		set_enemy_pos(map_data, x, y + 1);
	else if (map_data->map[y][x + 1] != 'C' && map_cpy[y][x + 1] == 'V')
		set_enemy_pos(map_data, x + 1, y);
}

int	check_tile_e(t_map *map_data, char **map_cpy, int x, int y)
{
	if (map_cpy[y][x] == 'E')
	{
		map_data->e_count++;
		map_cpy[y][x] = 'v';
		return (2);
	}
	if (map_cpy[y][x] == 'V')
	{
		map_cpy[y][x] = 'v';
		return (1);
	}
	return (0);
}

void	check_path_e_core(t_map *map_data, char **map_cpy, int x, int y)
{
	int	w;
	int	a;
	int	s;
	int	d;

	w = check_tile_e(map_data, map_cpy, x, y - 1);
	a = check_tile_e(map_data, map_cpy, x - 1, y);
	s = check_tile_e(map_data, map_cpy, x, y + 1);
	d = check_tile_e(map_data, map_cpy, x + 1, y);
	if (w == 2)
		check_enemy_pos(map_data, map_cpy, x, y - 1);
	else if (a == 2)
		check_enemy_pos(map_data, map_cpy, x - 1, y);
	else if (s == 2)
		check_enemy_pos(map_data, map_cpy, x, y + 1);
	else if (d == 2)
		check_enemy_pos(map_data, map_cpy, x + 1, y);
	if (w == 1)
		check_path_e_core(map_data, map_cpy, x, y - 1);
	if (a == 1)
		check_path_e_core(map_data, map_cpy, x - 1, y);
	if (s == 1)
		check_path_e_core(map_data, map_cpy, x, y + 1);
	if (d == 1)
		check_path_e_core(map_data, map_cpy, x + 1, y);
}

void	check_path_e(t_map *map_data, char **map_cpy)
{
	map_data->r_x = 0;
	map_data->r_y = 0;
	map_data->e_count = 0;
	check_path_e_core(map_data, map_cpy, map_data->p_x, map_data->p_y);
	if (map_data->e_count == 0)
		proc_map_err(map_data->map, map_cpy, SL_ERR_PARAM,
			"check_map: There is no valid path to an exit\n");
	if (map_data->r_x != 0 && map_data->r_y != 0)
		map_data->map[map_data->r_y][map_data->r_x] = 'R';
}
