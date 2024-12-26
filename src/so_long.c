/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 09:16:59 by akyoshid          #+#    #+#             */
/*   Updated: 2024/12/26 17:23:25 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	quit_program(t_data *data)
{
	free_img(data, IMG_COUNT);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display((data->mlx));
	free(data->mlx);
	free_map(data->map_data.map);
}

void	put_suicune_to_window(t_data *data, int x, int y)
{
	if (data->suicune_count % 8 == 0)
		mlx_put_image_to_window(data->mlx, data->win,
			data->img[IMG_SUICUNE_1], x * 64, y * 64);
	else if (data->suicune_count % 8 == 1)
		mlx_put_image_to_window(data->mlx, data->win,
			data->img[IMG_SUICUNE_2], x * 64, y * 64);
	else if (data->suicune_count % 8 == 2)
		mlx_put_image_to_window(data->mlx, data->win,
			data->img[IMG_SUICUNE_3], x * 64, y * 64);
	else if (data->suicune_count % 8 == 3)
		mlx_put_image_to_window(data->mlx, data->win,
			data->img[IMG_SUICUNE_4], x * 64, y * 64);
	else if (data->suicune_count % 8 == 4)
		mlx_put_image_to_window(data->mlx, data->win,
			data->img[IMG_SUICUNE_5], x * 64, y * 64);
	else if (data->suicune_count % 8 == 5)
		mlx_put_image_to_window(data->mlx, data->win,
			data->img[IMG_SUICUNE_6], x * 64, y * 64);
	else if (data->suicune_count % 8 == 6)
		mlx_put_image_to_window(data->mlx, data->win,
			data->img[IMG_SUICUNE_7], x * 64, y * 64);
	else if (data->suicune_count % 8 == 7)
		mlx_put_image_to_window(data->mlx, data->win,
			data->img[IMG_SUICUNE_8], x * 64, y * 64);
}

void	put_images_to_window(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win,
		data->img[IMG_TILE], x * 64, y * 64);
	if (data->map_data.map[y][x] == '1')
		mlx_put_image_to_window(data->mlx, data->win,
			data->img[IMG_TREE], x * 64, y * 64);
	if (data->map_data.map[y][x] == 'C')
		mlx_put_image_to_window(data->mlx, data->win,
			data->img[IMG_MONSTER_BALL], x * 64, y * 64);
	if (data->map_data.map[y][x] == 'E')
		put_suicune_to_window(data, x, y);
	if (data->map_data.map[y][x] == 'P')
		mlx_put_image_to_window(data->mlx, data->win,
			data->img[IMG_PLAYER], x * 64, y * 64);
	// if (data->map_data.map[y][x] == 'R')
	// 	mlx_put_image_to_window(data->mlx, data->win,
	// 		data->img[IMG_ENEMY], x * 64, y * 64);
	// if (data->map_data.map[y][x] == 'L')
	// 	mlx_put_image_to_window(data->mlx, data->win,
	// 		data->img[IMG_LOSER], x * 64, y * 64);
}

void	refresh_display(t_data *data)
{
	int	x;
	int y;

	y = 0;
	// refresh_map(data);
	while (y < data->map_data.y_count)
	{
		x = 0;
		while (x < data->map_data.x_count)
		{
			put_images_to_window(data, x, y);
			x++;
		}
		y++;
	}
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
	proc_mlx_load_sprite(&data, 0);
	data.loop_count = 0;
	data.suicune_count = -1;
	data.key = 0;
	refresh_display(&data);

	mlx_loop_hook(data.mlx, loop_hook, &data);
	mlx_hook(data.win, DestroyNotify, StructureNotifyMask, mlx_loop_end, data.mlx);
	mlx_loop(data.mlx);

	quit_program(&data);
	ft_printf("\n\nfin\n\n\n");
	return (0);
}
