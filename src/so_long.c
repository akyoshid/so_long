/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 09:16:59 by akyoshid          #+#    #+#             */
/*   Updated: 2024/12/27 00:41:23 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	quit_program(t_data *data)
{
	mlx_destroy_image(data->mlx, data->buff_data.img);
	free_img(data, IMG_COUNT);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display((data->mlx));
	free(data->mlx);
	free_map(data->map_data.map);
}

unsigned int	get_pixel_from_image(t_img *img_data, int x, int y)
{
	int				offset;
	char			*p;
	unsigned int	pixel;

	offset = y * img_data->line_size + x * img_data->bytes_per_pixel;
	p = img_data->addr + offset;
	pixel = *(unsigned int *)p;
	return (pixel);
}

void	put_pixel_to_buff(
	t_img *buff_data, int pixel_x, int pixel_y, unsigned int pixel)
{
	int				offset;
	unsigned int	*dst;

	if (pixel == (unsigned int)0xFF000000)
		return ;
	offset = pixel_y * buff_data->line_size
		+ pixel_x * buff_data->bytes_per_pixel;
	dst = (unsigned int *)(buff_data->addr + offset);
	*dst = pixel;
}

void	put_image_to_buff(t_data *data, int img_code, int x, int y)
{
	int				pixel_x;
	int				pixel_y;
	unsigned int	pixel;

	pixel_y = 0;
	while (pixel_y < 64)
	{
		pixel_x = 0;
		while (pixel_x < 64)
		{
			pixel = get_pixel_from_image(
					&data->img_data[img_code], pixel_x, pixel_y);
			put_pixel_to_buff(&data->buff_data,
				x * 64 + pixel_x, y * 64 + pixel_y, pixel);
			pixel_x++;
		}
		pixel_y++;
	}
}

void	put_suicune_to_buff(t_data *data, int x, int y)
{
	if (data->suicune_count % 8 == 0)
		put_image_to_buff(data, IMG_SUICUNE_1, x, y);
	else if (data->suicune_count % 8 == 1)
		put_image_to_buff(data, IMG_SUICUNE_2, x, y);
	else if (data->suicune_count % 8 == 2)
		put_image_to_buff(data, IMG_SUICUNE_3, x, y);
	else if (data->suicune_count % 8 == 3)
		put_image_to_buff(data, IMG_SUICUNE_4, x, y);
	else if (data->suicune_count % 8 == 4)
		put_image_to_buff(data, IMG_SUICUNE_5, x, y);
	else if (data->suicune_count % 8 == 5)
		put_image_to_buff(data, IMG_SUICUNE_6, x, y);
	else if (data->suicune_count % 8 == 6)
		put_image_to_buff(data, IMG_SUICUNE_7, x, y);
	else if (data->suicune_count % 8 == 7)
		put_image_to_buff(data, IMG_SUICUNE_8, x, y);
}

void	put_images_to_buff(t_data *data, int x, int y)
{
	put_image_to_buff(data, IMG_TILE, x, y);
	if (data->map_data.map[y][x] == '1')
		put_image_to_buff(data, IMG_TREE, x, y);
	else if (data->map_data.map[y][x] == 'C')
		put_image_to_buff(data, IMG_MONSTER_BALL, x, y);
	else if (data->map_data.map[y][x] == 'E')
		put_suicune_to_buff(data, x, y);
	else if (data->map_data.map[y][x] == 'P')
		put_image_to_buff(data, IMG_PLAYER, x, y);
	// else if (data->map_data.map[y][x] == 'R')
	// 	put_image_to_buff(data, IMG_ENEMY, x, y);
	// else if (data->map_data.map[y][x] == 'L')
	// 	put_image_to_buff(data, IMG_LOSER, x, y);
}

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
