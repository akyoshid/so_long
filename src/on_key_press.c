/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_key_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:25:27 by akyoshid          #+#    #+#             */
/*   Updated: 2024/12/28 15:25:43 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	on_key_press(int key_code, t_data *data)
{
	if (key_code == KEY_ESC)
		mlx_loop_end(data->mlx);
	else if (key_code == KEY_W)
		data->key = KEY_W;
	else if (key_code == KEY_A)
		data->key = KEY_A;
	else if (key_code == KEY_S)
		data->key = KEY_S;
	else if (key_code == KEY_D)
		data->key = KEY_D;
	else if (key_code == KEY_X)
		data->key = KEY_X;
	return (0);
}
