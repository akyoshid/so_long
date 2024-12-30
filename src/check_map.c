/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 09:49:37 by akyoshid          #+#    #+#             */
/*   Updated: 2024/12/31 03:29:58 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_size(t_map *map_data)
{
	if (map_data->x_count > 60 || map_data->y_count > 32)
		proc_map_err(map_data->map, NULL, SL_ERR_PARAM,
			"check_map: The map is too big: "
			"Maximum size is 32 (height) and 60 (width)\n");
}

void	check_rectangular(t_map *map_data)
{
	int	i;

	map_data->x_count = (int)ft_strlen(map_data->map[0]) - 1;
	i = 1;
	while (map_data->map[i] != NULL)
	{
		if (map_data->map[i + 1] == NULL)
		{
			if (!((map_data->x_count == (int)ft_strlen(map_data->map[i]) - 1
						&& map_data->map[i][map_data->x_count] == '\n')
				|| (map_data->x_count == (int)ft_strlen(map_data->map[i])
					&& map_data->map[i][map_data->x_count - 1] != '\n')))
			{
				proc_map_err(map_data->map, NULL, SL_ERR_PARAM,
					"check_map: The map is not rectangular\n");
			}
		}
		else
		{
			if (map_data->x_count != (int)ft_strlen(map_data->map[i]) - 1)
				proc_map_err(map_data->map, NULL, SL_ERR_PARAM,
					"check_map: The map is not rectangular\n");
		}
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

char	**cpy_map(t_map *map_data)
{
	char	**temp;
	int		i;

	temp = (char **)malloc(sizeof(char *) * (map_data->y_count + 1));
	if (temp == NULL)
		proc_map_err(map_data->map, NULL, SL_ERR_MALLOC, NULL);
	i = 0;
	while (i < map_data->y_count)
	{
		temp[i] = (char *)malloc(sizeof(char) * (map_data->x_count + 1));
		if (temp[i] == NULL)
			proc_map_err(map_data->map, temp, SL_ERR_MALLOC, NULL);
		ft_strlcpy(temp[i], map_data->map[i], map_data->x_count + 1);
		i++;
	}
	temp[i] = NULL;
	return (temp);
}

void	check_map(t_map *map_data)
{
	char	**map_cpy;

	check_rectangular(map_data);
	check_size(map_data);
	check_wall(map_data);
	check_component(map_data);
	map_cpy = cpy_map(map_data);
	check_path_c(map_data, map_cpy);
	check_path_e(map_data, map_cpy);
	free_map(map_cpy);
}
