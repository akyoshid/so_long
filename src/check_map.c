/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 09:49:37 by akyoshid          #+#    #+#             */
/*   Updated: 2024/12/24 15:39:30 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_rectangular(t_map *map_data)
{
	int	i;

	map_data->x_count = (int)ft_strlen(map_data->map[0]) - 1;
	i = 1;
	while (map_data->map[i] != NULL)
	{
		if (map_data->x_count != (int)ft_strlen(map_data->map[i]) - 1)
			proc_map_err(map_data->map, NULL, SL_ERR_PARAM,
				"check_map: The map is not rectangular\n");
		i++;
	}
}

void	check_wall(t_map *map_data)
{
	int	i;

	i = 0;
	while (i < map_data->x_count)
	{
		if (map_data->map[0][i] != '1'
			|| map_data->map[map_data->y_count - 1][i] != '1')
			proc_map_err(map_data->map, NULL, SL_ERR_PARAM,
				"check_map: The map is not surrounded by walls\n");
		i++;
	}
	i = 0;
	while (i < map_data->y_count)
	{
		if (map_data->map[i][0] != '1'
			|| map_data->map[i][map_data->x_count - 1] != '1')
			proc_map_err(map_data->map, NULL, SL_ERR_PARAM,
				"check_map: The map is not surrounded by walls\n");
		i++;
	}
}
