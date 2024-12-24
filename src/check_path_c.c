/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:46:00 by akyoshid          #+#    #+#             */
/*   Updated: 2024/12/24 16:01:20 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_tile_c(char **map_cpy, int x, int y, int *count)
{
	if (map_cpy[y][x] == 'C')
	{
		map_cpy[y][x] = 'V';
		(*count)++;
		return (1);
	}
	if (map_cpy[y][x] == '0')
	{
		map_cpy[y][x] = 'V';
		return (1);
	}
	return (0);
}

void	check_path_c_core(char **map_cpy, int y, int x, int *count)
{
	if (check_tile_c(map_cpy, y - 1, x, count) == 1)
		check_path_c_core(map_cpy, y - 1, x, count);
	if (check_tile_c(map_cpy, y + 1, x, count) == 1)
		check_path_c_core(map_cpy, y + 1, x, count);
	if (check_tile_c(map_cpy, y, x - 1, count) == 1)
		check_path_c_core(map_cpy, y, x - 1, count);
	if (check_tile_c(map_cpy, y, x + 1, count) == 1)
		check_path_c_core(map_cpy, y, x + 1, count);
}

void	check_path_c(t_map *map_data, char **map_cpy)
{
	int	count;

	count = 0;
	check_path_c_core(map_cpy, map_data->p_y, map_data->p_x, &count);
	if (count != map_data->c_count)
		proc_map_err(map_data->map, map_cpy, SL_ERR_PARAM,
			"check_map: There is no valid path to some collectives\n");
}
