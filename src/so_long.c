/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 09:16:59 by akyoshid          #+#    #+#             */
/*   Updated: 2024/12/24 15:51:03 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char *argv[])
{
	int		fd;
	t_map	map_data;

	check_arg(argc, argv[1]);
	fd = open_map_file(argv[1]);
	read_map_file(fd, &map_data);
	check_map(&map_data);
	// ft_printf("p_x: %d\np_y: %d\n", map_data.p_x, map_data.p_y);
	// ft_printf("x_count: %d\ny_count: %d\n", map_data.x_count, map_data.y_count);
	free_map(map_data.map);
	return (0);
}
