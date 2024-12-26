/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_mlx_load_sprite.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 14:57:51 by akyoshid          #+#    #+#             */
/*   Updated: 2024/12/26 21:37:38 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	after_mlx_xpm_file_to_image(t_data *data, int img_code)
{
	if (data->img_data[img_code].img == NULL)
	{
		free_img(data, img_code);
		proc_mlx_err(data, SL_ERR_MLX_XPM_2_IMG,
			"mlx_xpm_file_to_image: Failed to load XPM file\n");
	}
	proc_mlx_get_data_addr(&data->img_data[img_code]);
}

void	proc_mlx_load_suicune(t_data *data, int *trash)
{
	data->img_data[IMG_SUICUNE_1].img = mlx_xpm_file_to_image(
			data->mlx, "assets/suicune_1.xpm", trash, trash);
	after_mlx_xpm_file_to_image(data, IMG_SUICUNE_1);
	data->img_data[IMG_SUICUNE_2].img = mlx_xpm_file_to_image(
			data->mlx, "assets/suicune_2.xpm", trash, trash);
	after_mlx_xpm_file_to_image(data, IMG_SUICUNE_2);
	data->img_data[IMG_SUICUNE_3].img = mlx_xpm_file_to_image(
			data->mlx, "assets/suicune_3.xpm", trash, trash);
	after_mlx_xpm_file_to_image(data, IMG_SUICUNE_3);
	data->img_data[IMG_SUICUNE_4].img = mlx_xpm_file_to_image(
			data->mlx, "assets/suicune_4.xpm", trash, trash);
	after_mlx_xpm_file_to_image(data, IMG_SUICUNE_4);
	data->img_data[IMG_SUICUNE_5].img = mlx_xpm_file_to_image(
			data->mlx, "assets/suicune_5.xpm", trash, trash);
	after_mlx_xpm_file_to_image(data, IMG_SUICUNE_5);
	data->img_data[IMG_SUICUNE_6].img = mlx_xpm_file_to_image(
			data->mlx, "assets/suicune_6.xpm", trash, trash);
	after_mlx_xpm_file_to_image(data, IMG_SUICUNE_6);
	data->img_data[IMG_SUICUNE_7].img = mlx_xpm_file_to_image(
			data->mlx, "assets/suicune_7.xpm", trash, trash);
	after_mlx_xpm_file_to_image(data, IMG_SUICUNE_7);
	data->img_data[IMG_SUICUNE_8].img = mlx_xpm_file_to_image(
			data->mlx, "assets/suicune_8.xpm", trash, trash);
	after_mlx_xpm_file_to_image(data, IMG_SUICUNE_8);
}

void	proc_mlx_load_sprite(t_data *data)
{
	int	trash;

	trash = 0;
	data->img_data[IMG_ENEMY].img = mlx_xpm_file_to_image(
			data->mlx, "assets/enemy.xpm", &trash, &trash);
	after_mlx_xpm_file_to_image(data, IMG_ENEMY);
	data->img_data[IMG_LOSER].img = mlx_xpm_file_to_image(
			data->mlx, "assets/loser.xpm", &trash, &trash);
	after_mlx_xpm_file_to_image(data, IMG_LOSER);
	data->img_data[IMG_MONSTER_BALL].img = mlx_xpm_file_to_image(
			data->mlx, "assets/monster_ball.xpm", &trash, &trash);
	after_mlx_xpm_file_to_image(data, IMG_MONSTER_BALL);
	data->img_data[IMG_PLAYER].img = mlx_xpm_file_to_image(
			data->mlx, "assets/player.xpm", &trash, &trash);
	after_mlx_xpm_file_to_image(data, IMG_PLAYER);
	proc_mlx_load_suicune(data, &trash);
	data->img_data[IMG_TILE].img = mlx_xpm_file_to_image(
			data->mlx, "assets/tile.xpm", &trash, &trash);
	after_mlx_xpm_file_to_image(data, IMG_TILE);
	data->img_data[IMG_TREE].img = mlx_xpm_file_to_image(
			data->mlx, "assets/tree.xpm", &trash, &trash);
	after_mlx_xpm_file_to_image(data, IMG_TREE);
}
