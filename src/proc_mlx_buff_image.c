/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_mlx_buff_image.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:56:37 by akyoshid          #+#    #+#             */
/*   Updated: 2024/12/26 19:57:20 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	set_bytes_per_pixel(int *bytes_per_pixel, int bits_per_pixel)
{
	*bytes_per_pixel = bits_per_pixel / 8;
	if (bits_per_pixel % 8 != 0)
		(*bytes_per_pixel)++;
}

void	proc_mlx_buff_image(t_data *data)
{
	data->width = data->map_data.x_count * 64;
	data->height = data->map_data.y_count * 64;
	data->buff.img = mlx_new_image(
						data->mlx, data->width, data->height);
	if (data->buff.img == NULL)
	{
		free_img(data, IMG_COUNT);
		proc_mlx_err(data, SL_ERR_MLX_NEW_IMG,
			"mlx_new_image: Failed to create a new MLX compatible image\n");
	}
	data->buff.addr = mlx_get_data_addr(data->buff.img,
						&data->buff.bits_per_pixel,
						&data->buff.line_size,
						&data->buff.endian);
	set_bytes_per_pixel(&data->buff.bytes_per_pixel, data->buff.bits_per_pixel);
}
