/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_mlx_load_sprite.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 14:57:51 by akyoshid          #+#    #+#             */
/*   Updated: 2024/12/25 15:47:07 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	proc_xpm_2_img_err(t_data *data, int img_code)
{
	free_img(data, img_code);
	proc_mlx_err(data, SL_ERR_MLX_XPM_2_IMG,
		"mlx_xpm_file_to_image: Failed to load XPM file\n");
}

void	proc_mlx_load_suicune_2(t_data *data, int trash)
{
	data->img[IMG_SUICUNE_5] = mlx_xpm_file_to_image(
			data->mlx, "assets/suicune_5.xpm", &trash, &trash);
	if (data->img[IMG_SUICUNE_5] == NULL)
		proc_xpm_2_img_err(data, IMG_SUICUNE_5);
	data->img[IMG_SUICUNE_6] = mlx_xpm_file_to_image(
			data->mlx, "assets/suicune_6.xpm", &trash, &trash);
	if (data->img[IMG_SUICUNE_6] == NULL)
		proc_xpm_2_img_err(data, IMG_SUICUNE_6);
	data->img[IMG_SUICUNE_7] = mlx_xpm_file_to_image(
			data->mlx, "assets/suicune_7.xpm", &trash, &trash);
	if (data->img[IMG_SUICUNE_7] == NULL)
		proc_xpm_2_img_err(data, IMG_SUICUNE_7);
	data->img[IMG_SUICUNE_8] = mlx_xpm_file_to_image(
			data->mlx, "assets/suicune_8.xpm", &trash, &trash);
	if (data->img[IMG_SUICUNE_8] == NULL)
		proc_xpm_2_img_err(data, IMG_SUICUNE_8);
}

void	proc_mlx_load_suicune_1(t_data *data, int trash)
{
	data->img[IMG_SUICUNE_1] = mlx_xpm_file_to_image(
			data->mlx, "assets/suicune_1.xpm", &trash, &trash);
	if (data->img[IMG_SUICUNE_1] == NULL)
		proc_xpm_2_img_err(data, IMG_SUICUNE_1);
	data->img[IMG_SUICUNE_2] = mlx_xpm_file_to_image(
			data->mlx, "assets/suicune_2.xpm", &trash, &trash);
	if (data->img[IMG_SUICUNE_2] == NULL)
		proc_xpm_2_img_err(data, IMG_SUICUNE_2);
	data->img[IMG_SUICUNE_3] = mlx_xpm_file_to_image(
			data->mlx, "assets/suicune_3.xpm", &trash, &trash);
	if (data->img[IMG_SUICUNE_3] == NULL)
		proc_xpm_2_img_err(data, IMG_SUICUNE_3);
	data->img[IMG_SUICUNE_4] = mlx_xpm_file_to_image(
			data->mlx, "assets/suicune_4.xpm", &trash, &trash);
	if (data->img[IMG_SUICUNE_4] == NULL)
		proc_xpm_2_img_err(data, IMG_SUICUNE_4);
	proc_mlx_load_suicune_2(data, 0);
}

void	proc_mlx_load_sprite(t_data *data, int trash)
{
	data->img[IMG_ENEMY] = mlx_xpm_file_to_image(
			data->mlx, "assets/enemy.xpm", &trash, &trash);
	if (data->img[IMG_ENEMY] == NULL)
		proc_xpm_2_img_err(data, IMG_ENEMY);
	data->img[IMG_LOSER] = mlx_xpm_file_to_image(
			data->mlx, "assets/loser.xpm", &trash, &trash);
	if (data->img[IMG_LOSER] == NULL)
		proc_xpm_2_img_err(data, IMG_LOSER);
	data->img[IMG_MONSTER_BALL] = mlx_xpm_file_to_image(
			data->mlx, "assets/monster_ball.xpm", &trash, &trash);
	if (data->img[IMG_MONSTER_BALL] == NULL)
		proc_xpm_2_img_err(data, IMG_MONSTER_BALL);
	data->img[IMG_PLAYER] = mlx_xpm_file_to_image(
			data->mlx, "assets/player.xpm", &trash, &trash);
	if (data->img[IMG_PLAYER] == NULL)
		proc_xpm_2_img_err(data, IMG_PLAYER);
	proc_mlx_load_suicune_1(data, 0);
	data->img[IMG_TILE] = mlx_xpm_file_to_image(
			data->mlx, "assets/tile.xpm", &trash, &trash);
	if (data->img[IMG_TILE] == NULL)
		proc_xpm_2_img_err(data, IMG_TILE);
	data->img[IMG_TREE] = mlx_xpm_file_to_image(
			data->mlx, "assets/tree.xpm", &trash, &trash);
	if (data->img[IMG_TREE] == NULL)
		proc_xpm_2_img_err(data, IMG_TREE);
}
