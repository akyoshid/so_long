/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 09:16:59 by akyoshid          #+#    #+#             */
/*   Updated: 2024/12/23 04:31:38 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char *argv[])
{
	int		fd;
	t_map	map_data;

	if (argc != 2)
		proc_err(SL_ERR_NUM_OF_ARG, NULL);
	fd = open_map_file(argv[1]);
	map_data.map = read_map_file(fd, NULL, 0, 64);
	free_map(map_data.map);
	return (0);
}
