/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:46:00 by akyoshid          #+#    #+#             */
/*   Updated: 2024/12/28 20:25:48 by akyoshid         ###   ########.fr       */
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

void	check_path_c_core(char **map_cpy, int x, int y, int *count)
{
	int	w;
	int	a;
	int	s;
	int	d;

	w = check_tile_c(map_cpy, x, y - 1, count);
	a = check_tile_c(map_cpy, x - 1, y, count);
	s = check_tile_c(map_cpy, x, y + 1, count);
	d = check_tile_c(map_cpy, x + 1, y, count);
	if (w == 1)
		check_path_c_core(map_cpy, x, y - 1, count);
	if (a == 1)
		check_path_c_core(map_cpy, x - 1, y, count);
	if (s == 1)
		check_path_c_core(map_cpy, x, y + 1, count);
	if (d == 1)
		check_path_c_core(map_cpy, x + 1, y, count);
}

void	check_path_c(t_map *map_data, char **map_cpy)
{
	int	count;

	count = 0;
	check_path_c_core(map_cpy, map_data->p_x, map_data->p_y, &count);
	if (count != map_data->c_count)
		proc_map_err(map_data->map, map_cpy, SL_ERR_PARAM,
			"check_map: There is no valid path to some collectives\n");
}
