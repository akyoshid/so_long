/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_mlx_err.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 15:00:04 by akyoshid          #+#    #+#             */
/*   Updated: 2024/12/25 15:00:18 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	proc_mlx_err(t_data *data, int err_code, void *param)
{
	if (err_code >= SL_ERR_MLX_XPM_2_IMG)
		mlx_destroy_window(data->mlx, data->win);
	if (err_code >= SL_ERR_MLX_NEW_WIN)
	{
		mlx_destroy_display((data->mlx));
		free(data->mlx);
	}
	free_map(data->map_data.map);
	proc_err(SL_ERR_PARAM, param);
}
