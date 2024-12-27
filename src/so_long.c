/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 09:16:59 by akyoshid          #+#    #+#             */
/*   Updated: 2024/12/27 00:46:48 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	refresh_display(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	// refresh_map(data);
	while (y < data->map_data.y_count)
	{
		x = 0;
		while (x < data->map_data.x_count)
		{
			put_images_to_buff(data, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->buff_data.img, 0, 0);
}

int	loop_hook(t_data *data)
{
	if (data->loop_count % (256 * 2) == 0)
	{
		if (data->loop_count % (256 * 8) == 0)
			data->suicune_count++;
		if (data->loop_count % (256 * 64) == 0)
		{
			ft_printf("move_enemy()\n");
			// move_enemy(data);
			data->loop_count = 0;
		}
		refresh_display(data);
	}
	data->loop_count++;
	return (0);
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
	data.loop_count = 0;
	data.suicune_count = -1;
	data.key = 0;
	refresh_display(&data);

	mlx_loop_hook(data.mlx, loop_hook, &data);
	mlx_hook(data.win, DestroyNotify, StructureNotifyMask,
		mlx_loop_end, data.mlx);
	mlx_loop(data.mlx);

	quit_program(&data);
	return (0);
}
