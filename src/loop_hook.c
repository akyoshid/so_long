/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:26:32 by akyoshid          #+#    #+#             */
/*   Updated: 2024/12/29 14:58:45 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

# define INDEX_W 0
# define INDEX_A 1
# define INDEX_S 2
# define INDEX_D 3

// return random number 0 ~ 255
// if open() fails, return -1
// if close() fails, return -2
// if read() fails, return -3
int	ft_rand_256(void)
{
	int				fd;
	int				read_rv;
	unsigned char	random_byte;

	fd = open("/dev/urandom", O_RDONLY);
	if (fd == -1)
		return (-1);
	read_rv = read(fd, &random_byte, 1);
	if (close(fd) == -1)
		return (-2);
	if (read_rv == -1)
		return (-3);
	return ((int)random_byte);
}

void	set_enemy_dst_tile(t_data *data, char (*dst_tile)[4])
{
	(*dst_tile)[INDEX_W]
		= data->map_data.map[data->map_data.r_y - 1][data->map_data.r_x];
	(*dst_tile)[INDEX_A]
		= data->map_data.map[data->map_data.r_y][data->map_data.r_x - 1];
	(*dst_tile)[INDEX_S]
		= data->map_data.map[data->map_data.r_y + 1][data->map_data.r_x];
	(*dst_tile)[INDEX_D]
		= data->map_data.map[data->map_data.r_y][data->map_data.r_x + 1];
}

int	count_enemy_walkable_tile(char *dst_tile)
{
	int count;

	count = 0;
	if (dst_tile[INDEX_W] == '0')
		count++;
	if (dst_tile[INDEX_A] == '0')
		count++;
	if (dst_tile[INDEX_S] == '0')
		count++;
	if (dst_tile[INDEX_D] == '0')
		count++;
	return (count);
}

void	move_enemy_core(t_data *data, int index_code)
{
	if (index_code == INDEX_W)
	{
		data->map_data.map[data->map_data.r_y][data->map_data.r_x] = '0';
		data->map_data.r_y--;
		data->map_data.map[data->map_data.r_y][data->map_data.r_x] = 'R';
	}
	else if (index_code == INDEX_A)
	{
		data->map_data.map[data->map_data.r_y][data->map_data.r_x] = '0';
		data->map_data.r_x--;
		data->map_data.map[data->map_data.r_y][data->map_data.r_x] = 'R';
	}
	else if (index_code == INDEX_S)
	{
		data->map_data.map[data->map_data.r_y][data->map_data.r_x] = '0';
		data->map_data.r_y++;
		data->map_data.map[data->map_data.r_y][data->map_data.r_x] = 'R';
	}
	else if (index_code == INDEX_D)
	{
		data->map_data.map[data->map_data.r_y][data->map_data.r_x] = '0';
		data->map_data.r_x++;
		data->map_data.map[data->map_data.r_y][data->map_data.r_x] = 'R';
	}
}

void	choose_enemy_dst_tile(t_data *data, char *dst_tile, int count, int rand)
{
	if (dst_tile[INDEX_W] == '0')
	{
		if (rand == count)
			move_enemy_core(data, INDEX_W);
		count++;
	}
	if (dst_tile[INDEX_A] == '0')
	{
		if (rand == count)
			move_enemy_core(data, INDEX_A);
		count++;
	}
	if (dst_tile[INDEX_S] == '0')
	{
		if (rand == count)
			move_enemy_core(data, INDEX_S);
		count++;
	}
	if (dst_tile[INDEX_D] == '0')
	{
		if (rand == count)
			move_enemy_core(data, INDEX_D);
		count++;
	}
}

void	move_enemy(t_data *data)
{
	char	dst_tile[4];
	int		tile_count;
	int		rand;

	if (data->loop_count == 0
		|| data->map_data.map[data->map_data.r_y][data->map_data.r_x] != 'R')
		return ;
	set_enemy_dst_tile(data, &dst_tile);
	tile_count = count_enemy_walkable_tile(dst_tile);
	rand = ft_rand_256() % tile_count;
	choose_enemy_dst_tile(data, dst_tile, 0, rand);
}

int	loop_hook(t_data *data)
{
	if (data->loop_count % (256 * 2) == 0)
	{
		if (data->loop_count % (256 * 16) == 0)
			data->suicune_count++;
		if (data->loop_count % (256 * 256) == 0)
		{
			move_enemy(data);
			data->loop_count = 0;
		}
		refresh_display(data);
		if (data->exit_flag == 1)
			handle_exit_flag(data);
		if (data->game_over_flag == 1)
			handle_game_over_flag(data);
	}
	data->loop_count++;
	return (0);
}
