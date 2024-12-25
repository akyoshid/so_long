/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_mlx_new_window.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 14:55:54 by akyoshid          #+#    #+#             */
/*   Updated: 2024/12/25 15:53:15 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	proc_mlx_new_window(t_data *data)
{
	data->win = mlx_new_window(data->mlx,
			data->map_data.x_count * 64,
			data->map_data.y_count * 64, "so_long");
	if (data->win == NULL)
		proc_mlx_err(data, SL_ERR_MLX_NEW_WIN,
			"mlx_new_window: Failed to create a new window\n");
}
