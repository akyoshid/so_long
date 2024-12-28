/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images_to_buff.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:45:10 by akyoshid          #+#    #+#             */
/*   Updated: 2024/12/28 20:43:52 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
	else if (data->map_data.map[y][x] == 'R')
		put_image_to_buff(data, IMG_ENEMY, x, y);
	else if (data->map_data.map[y][x] == 'L')
		put_image_to_buff(data, IMG_LOSER, x, y);
}
