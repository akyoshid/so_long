/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_mlx_buff_image.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:56:37 by akyoshid          #+#    #+#             */
/*   Updated: 2024/12/26 20:53:53 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
	proc_mlx_get_data_addr(&data->buff);
}
