/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 09:16:59 by akyoshid          #+#    #+#             */
/*   Updated: 2024/12/28 21:08:22 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_so_long(t_data *data)
{
	data->map_data.c_collected = 0;
	data->loop_count = 0;
	data->suicune_count = -1;
	data->key = 0;
	data->move_count = 0;
	data->exit_flag = 0;
	data->game_over_flag = 0;
	refresh_display(data);
}

int	main(int argc, char *argv[])
{
	int		fd;
	t_data	data;

	check_arg(argc, argv[1]);
	fd = open_map_file(argv[1]);
	read_map_file(fd, &data.map_data);
	check_map(&data.map_data);
	proc_mlx_init(&data);
	proc_mlx_new_window(&data);
	proc_mlx_load_sprite(&data);
	proc_mlx_buff_image(&data);
	init_so_long(&data);
	mlx_loop_hook(data.mlx, loop_hook, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, on_key_press, &data);
	mlx_hook(data.win, DestroyNotify, StructureNotifyMask,
		mlx_loop_end, data.mlx);
	mlx_loop(data.mlx);
	quit_program(&data);
	return (0);
}
