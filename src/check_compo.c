/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_compo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 09:51:11 by akyoshid          #+#    #+#             */
/*   Updated: 2024/12/23 09:53:00 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_component_loop(t_map *map_data, int *e_count, int *p_count)
{
	int	x;
	int	y;

	y = -1;
	while (++y < map_data->y_count)
	{
		x = -1;
		while (++x < map_data->x_count)
		{
			if (map_data->map[y][x] == 'C')
				map_data->c_count++;
			else if (map_data->map[y][x] == 'E')
				(*e_count)++;
			else if (map_data->map[y][x] == 'P')
			{
				map_data->p_x = x;
				map_data->p_y = y;
				(*p_count)++;
			}
			else if (map_data->map[y][x] != '0' && map_data->map[y][x] != '1')
				proc_map_err(map_data,
					"check_map: Invalid components: "
					"Expected only '0', '1', 'C', 'E', 'P'\n");
		}
	}
}

void	check_component(t_map *map_data)
{
	int	e_count;
	int	p_count;

	map_data->c_count = 0;
	e_count = 0;
	p_count = 0;
	check_component_loop(map_data, &e_count, &p_count);
	if (map_data->c_count == 0)
		proc_map_err(map_data,
			"check_map: No collectives are included in the map\n");
	if (e_count == 0)
		proc_map_err(map_data,
			"check_map: No exit is included in the map\n");
	if (e_count > 1)
		proc_map_err(map_data,
			"check_map: Multiple exits are included in the map\n");
	if (p_count == 0)
		proc_map_err(map_data,
			"check_map: No player is included in the map\n");
	if (p_count != 1)
		proc_map_err(map_data,
			"check_map: Multiple players are included in the map\n");
}
