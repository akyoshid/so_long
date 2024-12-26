/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 14:58:47 by akyoshid          #+#    #+#             */
/*   Updated: 2024/12/26 20:51:23 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_img(t_data *data, int img_count)
{
	int	i;

	i = 0;
	while (i < img_count)
	{
		mlx_destroy_image(data->mlx, data->img_data[i].img);
		i++;
	}
}

void	set_bytes_per_pixel(int *bytes_per_pixel, int bits_per_pixel)
{
	*bytes_per_pixel = bits_per_pixel / 8;
	if (bits_per_pixel % 8 != 0)
		(*bytes_per_pixel)++;
}

void	proc_mlx_get_data_addr(t_img *img_data)
{
	img_data->addr = mlx_get_data_addr(img_data->img,
			&img_data->bits_per_pixel, &img_data->line_size, &img_data->endian);
	set_bytes_per_pixel(&img_data->bytes_per_pixel, img_data->bits_per_pixel);
}
