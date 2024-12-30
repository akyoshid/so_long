/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_display.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:24:56 by akyoshid          #+#    #+#             */
/*   Updated: 2024/12/29 15:19:57 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	refresh_display(t_data *data)
{
	int		x;
	int		y;
	char	*move_count_str;

	y = 0;
	if (data->key != 0 && data->game_over_flag == 0)
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
