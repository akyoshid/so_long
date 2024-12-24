/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 09:16:59 by akyoshid          #+#    #+#             */
/*   Updated: 2024/12/24 15:40:38 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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

int	check_tile_c(char **map_cpy, int x, int y, int *count)
{
	if (map_cpy[y][x]  == 'C')
	{
		map_cpy[y][x]  = 'V';
		(*count)++;
		return (1);
	}
	if (map_cpy[y][x]  == '0')
	{
		map_cpy[y][x]  = 'V';
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

int	check_tile_e(char **map_cpy, int x, int y, int *count)
{
	if (map_cpy[y][x]  == 'E')
	{
		map_cpy[y][x]  = 'v';
		(*count)++;
		return (0);
	}
	if (map_cpy[y][x]  == 'V')
	{
		map_cpy[y][x]  = 'v';
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

void	check_map(t_map *map_data)
{
	char	**map_cpy;

	check_rectangular(map_data);
	check_wall(map_data);
	check_component(map_data);
	map_cpy = cpy_map(map_data);
	check_path_c(map_data, map_cpy);
	check_path_e(map_data, map_cpy);
	free_map(map_cpy);
}

int	main(int argc, char *argv[])
{
	int		fd;
	t_map	map_data;

	check_arg(argc, argv[1]);
	fd = open_map_file(argv[1]);
	read_map_file(fd, &map_data);
	check_map(&map_data);
	ft_printf("p_x: %d\np_y: %d\n", map_data.p_x, map_data.p_y);
	ft_printf("x_count: %d\ny_count: %d\n", map_data.x_count, map_data.y_count);
	free_map(map_data.map);
	return (0);
}
