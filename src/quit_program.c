/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:46:08 by akyoshid          #+#    #+#             */
/*   Updated: 2024/12/27 00:46:29 by akyoshid         ###   ########.fr       */
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
