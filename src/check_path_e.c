/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_e.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:45:52 by akyoshid          #+#    #+#             */
/*   Updated: 2024/12/24 16:01:06 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_tile_e(char **map_cpy, int x, int y, int *count)
{
	if (map_cpy[y][x] == 'E')
	{
		map_cpy[y][x] = 'v';
		(*count)++;
		return (0);
	}
	if (map_cpy[y][x] == 'V')
	{
		map_cpy[y][x] = 'v';
		return (1);
	}
	return (0);
}

void	check_path_e_core(char **map_cpy, int y, int x, int *count)
{
	if (check_tile_e(map_cpy, y - 1, x, count) == 1)
		check_path_e_core(map_cpy, y - 1, x, count);
	if (check_tile_e(map_cpy, y + 1, x, count) == 1)
		check_path_e_core(map_cpy, y + 1, x, count);
	if (check_tile_e(map_cpy, y, x - 1, count) == 1)
		check_path_e_core(map_cpy, y, x - 1, count);
	if (check_tile_e(map_cpy, y, x + 1, count) == 1)
		check_path_e_core(map_cpy, y, x + 1, count);
}

void	check_path_e(t_map *map_data, char **map_cpy)
{
	int	count;

	count = 0;
	check_path_e_core(map_cpy, map_data->p_y, map_data->p_x, &count);
	if (count != 1)
		proc_map_err(map_data->map, map_cpy, SL_ERR_PARAM,
			"check_map: There is no valid path to an exit\n");
}
