/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 14:58:47 by akyoshid          #+#    #+#             */
/*   Updated: 2024/12/25 14:59:04 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_img(t_data *data, int img_count)
{
	int	i;

	i = 0;
	while (i < img_count)
	{
		mlx_destroy_image(data->mlx, data->img[i]);
		i++;
	}
}
