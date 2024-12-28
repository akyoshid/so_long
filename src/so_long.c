/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 09:16:59 by akyoshid          #+#    #+#             */
/*   Updated: 2024/12/28 15:18:27 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	set_current_and_dst_tile(t_data *data, char **current, char **dst)
{
	*current = &data->map_data.map[data->map_data.p_y][data->map_data.p_x];
	*dst = NULL;
	if (data->key == KEY_W
		|| (data->key == KEY_X
			&& data->map_data.map[data->map_data.p_y - 1][data->map_data.p_x]
		== 'R'))
		*dst = &data->map_data.map[data->map_data.p_y - 1][data->map_data.p_x];
	else if (data->key == KEY_A
		|| (data->key == KEY_X
			&& data->map_data.map[data->map_data.p_y][data->map_data.p_x - 1]
		== 'R'))
		*dst = &data->map_data.map[data->map_data.p_y][data->map_data.p_x - 1];
	else if (data->key == KEY_S
		|| (data->key == KEY_X
			&& data->map_data.map[data->map_data.p_y + 1][data->map_data.p_x]
		== 'R'))
		*dst = &data->map_data.map[data->map_data.p_y + 1][data->map_data.p_x];
	else if (data->key == KEY_D
		|| (data->key == KEY_X
			&& data->map_data.map[data->map_data.p_y][data->map_data.p_x + 1]
		== 'R'))
		*dst = &data->map_data.map[data->map_data.p_y][data->map_data.p_x + 1];
}

int	check_tile_walkable(t_data *data, char *dst_tile)
{
	if (*dst_tile == '0' || *dst_tile == 'C' || *dst_tile == 'L')
		return (1);
	else if (data->map_data.c_collected == data->map_data.c_count
		&& *dst_tile == 'E')
		return (1);
	return (0);
}

void	change_tile(t_data *data, char *current_tile, char *dst_tile)
{
	if (data->key != KEY_X)
	{
		if (*dst_tile == 'C')
			data->map_data.c_collected++;
		else if (*dst_tile == 'E')
			data->exit_flag = 1;
		*dst_tile = 'P';
		*current_tile = '0';
	}
	else
		*dst_tile = 'L';
}

void	change_player_pos(t_data *data)
{
	if (data->key == KEY_W)
		data->map_data.p_y--;
	if (data->key == KEY_A)
		data->map_data.p_x--;
	if (data->key == KEY_S)
		data->map_data.p_y++;
	if (data->key == KEY_D)
		data->map_data.p_x++;
}

void	refresh_map(t_data *data)
{
	char	*current_tile;
	char	*dst_tile;

	set_current_and_dst_tile(data, &current_tile, &dst_tile);
	if (data->key != KEY_X && check_tile_walkable(data, dst_tile) == 1)
	{
		change_tile(data, current_tile, dst_tile);
		change_player_pos(data);
		data->move_count++;
		ft_printf("number of movements: %u\n", data->move_count);
	}
	else if (data->key == KEY_X && dst_tile != NULL)
		change_tile(data, current_tile, dst_tile);
	data->key = 0;
}

void	refresh_display(t_data *data)
{
	int		x;
	int		y;
	char	*move_count_str;

	y = 0;
	if (data->key != 0)
		refresh_map(data);
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
	move_count_str = ft_itoa(data->move_count);
	mlx_string_put(data->mlx, data->win, 24, 32, 0x00ffffff, move_count_str);
	free(move_count_str);
}

int	loop_hook(t_data *data)
{
	if (data->loop_count % (256 * 2) == 0)
	{
		if (data->loop_count % (256 * 16) == 0)
			data->suicune_count++;
		if (data->loop_count % (256 * 256) == 0)
		{
			// move_enemy(data);
			data->loop_count = 0;
		}
		refresh_display(data);
		if (data->exit_flag == 1)
		{
			ft_printf("===============================\n");
			ft_printf("||          \033[1;32mGOTCHA!\033[0m          ||\n");
			ft_printf("||    \033[1;32mSuicune was caught!\033[0m    ||\n");
			ft_printf("================================\n");
			mlx_loop_end(data->mlx);
		}
	}
	data->loop_count++;
	return (0);
}

int	on_key_press(int key_code, t_data *data)
{
	if (key_code == KEY_ESC)
		mlx_loop_end(data->mlx);
	else if (key_code == KEY_W)
		data->key = KEY_W;
	else if (key_code == KEY_A)
		data->key = KEY_A;
	else if (key_code == KEY_S)
		data->key = KEY_S;
	else if (key_code == KEY_D)
		data->key = KEY_D;
	else if (key_code == KEY_X)
		data->key = KEY_X;
	return (0);
}

void	init_so_long(t_data *data)
{
	data->map_data.c_collected = 0;
	data->loop_count = 0;
	data->suicune_count = -1;
	data->key = 0;
	data->move_count = 0;
	data->exit_flag = 0;
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
