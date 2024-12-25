/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_mlx_load_sprite.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 14:57:51 by akyoshid          #+#    #+#             */
/*   Updated: 2024/12/25 15:17:18 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	proc_xpm_2_img_err(t_data *data, int img_code)
{
	free_img(data, img_code);
	proc_mlx_err(data, SL_ERR_MLX_XPM_2_IMG,
		"mlx_xpm_file_to_image: Failed to load XPM file\n");
}

void	proc_mlx_load_suicune(t_data *data, int i)
{
	if ((data->img[IMG_EXIT_1] = mlx_xpm_file_to_image(data->mlx,
									"assets/suicune_1.xpm", &i, &i)) == NULL)
		proc_xpm_2_img_err(data, IMG_EXIT_1);
	if ((data->img[IMG_EXIT_2] = mlx_xpm_file_to_image(data->mlx,
									"assets/suicune_2.xpm", &i, &i)) == NULL)
		proc_xpm_2_img_err(data, IMG_EXIT_2);
	if ((data->img[IMG_EXIT_3] = mlx_xpm_file_to_image(data->mlx,
									"assets/suicune_3.xpm", &i, &i)) == NULL)
		proc_xpm_2_img_err(data, IMG_EXIT_3);
	if ((data->img[IMG_EXIT_4] = mlx_xpm_file_to_image(data->mlx,
									"assets/suicune_4.xpm", &i, &i)) == NULL)
		proc_xpm_2_img_err(data, IMG_EXIT_4);
	if ((data->img[IMG_EXIT_5] = mlx_xpm_file_to_image(data->mlx,
									"assets/suicune_5.xpm", &i, &i)) == NULL)
		proc_xpm_2_img_err(data, IMG_EXIT_5);
	if ((data->img[IMG_EXIT_6] = mlx_xpm_file_to_image(data->mlx,
									"assets/suicune_6.xpm", &i, &i)) == NULL)
		proc_xpm_2_img_err(data, IMG_EXIT_6);
	if ((data->img[IMG_EXIT_7] = mlx_xpm_file_to_image(data->mlx,
									"assets/suicune_7.xpm", &i, &i)) == NULL)
		proc_xpm_2_img_err(data, IMG_EXIT_7);
	if ((data->img[IMG_EXIT_8] = mlx_xpm_file_to_image(data->mlx,
									"assets/suicune_8.xpm", &i, &i)) == NULL)
		proc_xpm_2_img_err(data, IMG_EXIT_8);
}

void	proc_mlx_load_sprite(t_data *data)
{
	int	trash;

	if ((data->img[IMG_ENEMY] = mlx_xpm_file_to_image(data->mlx,
		"assets/enemy.xpm", &trash, &trash)) == NULL)
		proc_xpm_2_img_err(data, IMG_ENEMY);
	if ((data->img[IMG_LOSER] = mlx_xpm_file_to_image(data->mlx,
		"assets/loser.xpm", &trash, &trash)) == NULL)
		proc_xpm_2_img_err(data, IMG_LOSER);
	if ((data->img[IMG_MONSTER_BALL] = mlx_xpm_file_to_image(data->mlx,
		"assets/monster_ball.xpm", &trash, &trash)) == NULL)
		proc_xpm_2_img_err(data, IMG_MONSTER_BALL);
	if ((data->img[IMG_PLAYER] = mlx_xpm_file_to_image(data->mlx,
		"assets/player.xpm", &trash, &trash)) == NULL)
		proc_xpm_2_img_err(data, IMG_PLAYER);
	proc_mlx_load_suicune(data, 0);
	if ((data->img[IMG_TILE] = mlx_xpm_file_to_image(data->mlx,
		"assets/tile.xpm", &trash, &trash)) == NULL)
		proc_xpm_2_img_err(data, IMG_TILE);
	if ((data->img[IMG_TREE] = mlx_xpm_file_to_image(data->mlx,
		"assets/tree.xpm", &trash, &trash)) == NULL)
		proc_xpm_2_img_err(data, IMG_TREE);
}
