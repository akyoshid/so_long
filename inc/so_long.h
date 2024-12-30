/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:24:44 by akyoshid          #+#    #+#             */
/*   Updated: 2024/12/30 09:45:51 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <stdbool.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>
# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"
# include "../libft/inc/get_next_line_bonus.h"

# define SL_ERR_PARAM 0
# define SL_ERR_OPEN 1
# define SL_ERR_MALLOC 2
# define SL_ERR_CLOSE 3

# define SL_ERR_MLX_INIT 0
# define SL_ERR_MLX_NEW_WIN 1
# define SL_ERR_MLX_XPM_2_IMG 2
# define SL_ERR_MLX_NEW_IMG 3

# define IMG_ENEMY 0
# define IMG_LOSER 1
# define IMG_MONSTER_BALL 2
# define IMG_PLAYER 3
# define IMG_SUICUNE_1 4
# define IMG_SUICUNE_2 5
# define IMG_SUICUNE_3 6
# define IMG_SUICUNE_4 7
# define IMG_SUICUNE_5 8
# define IMG_SUICUNE_6 9
# define IMG_SUICUNE_7 10
# define IMG_SUICUNE_8 11
# define IMG_TILE 12
# define IMG_TREE 13
# define IMG_COUNT 14

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_X 120

# define INDEX_W 0
# define INDEX_A 1
# define INDEX_S 2
# define INDEX_D 3

# define RAND_ERR_OPEN 1
# define RAND_ERR_READ 2
# define RAND_ERR_CLOSE 3

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		bytes_per_pixel;
	int		line_size;
	int		endian;
}			t_img;

typedef struct s_map
{
	char	**map;
	int		x_count;
	int		y_count;
	int		c_count;
	int		c_collected;
	int		p_x;
	int		p_y;
	int		r_x;
	int		r_y;
}			t_map;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	int				width;
	int				height;
	t_map			map_data;
	t_img			img_data[14];
	t_img			buff_data;
	int				loop_count;
	unsigned char	suicune_count;
	int				key;
	unsigned int	move_count;
	bool			exit_flag;
	bool			game_over_flag;
}			t_data;

// check_arg.c
void			check_argc(int argc);
void			check_file_ext(char *map_file);
void			check_arg(int argc, char *map_file);
// check_compo.c
void			check_invalid_component(
					t_map *map_data, int *e_count, int *p_count);
void			check_component(t_map *map_data);
// check_map.c
void			check_rectangular(t_map *map_data);
void			check_wall(t_map *map_data);
char			**cpy_map(t_map *map_data);
void			check_map(t_map *map_data);
// check_path_c.c
int				check_tile_c(char **map_cpy, int x, int y, int *count);
void			check_path_c_core(char **map_cpy, int x, int y, int *count);
void			check_path_c(t_map *map_data, char **map_cpy);
// check_path_e.c
int				check_tile_e(char **map_cpy, int x, int y);
void			check_path_e_core(
					t_map *map_data, char **map_cpy, int x, int y);
void			check_path_e(t_map *map_data, char **map_cpy);
// ft_rand_256.c
int				ft_rand_256(void);
void			proc_rand_err(t_data *data, int rand);
// handle_flag.c
void			handle_exit_flag(t_data *data);
void			handle_game_over_flag(t_data *data);
// img_utils.c
void			free_img(t_data *data, int img_count);
void			set_bytes_per_pixel(int *bytes_per_pixel, int bits_per_pixel);
void			proc_mlx_get_data_addr(t_img *img_data);
// loop_hook.c
int				loop_hook(t_data *data);
// map_utils.c
void			proc_map_err(
					char **map_1, char **map_2, int err_code, void *param);
void			free_map(char **map);
// move_enemy_utils.c
void			set_enemy_dst_tile(t_data *data, char (*dst_tile)[4]);
void			eliminate_player(t_data *data, char *dst_tile);
int				count_enemy_walkable_tile(char *dst_tile);
int				ft_rand_256(void);
void			choose_enemy_dst_tile(
					t_data *data, char *dst_tile, int count, int rand);
// move_enemy.c
void			move_enemy_core(t_data *data, int index_code);
void			move_enemy(t_data *data);
// on_key_press.c
int				on_key_press(int key_code, t_data *data);
// open_map_file.c
int				open_map_file(char *map_file);
// proc_err.c
void			proc_err(int err_code, void *param);
// proc_mlx_buff_image.c
void			set_bytes_per_pixel(int *bytes_per_pixel, int bits_per_pixel);
void			proc_mlx_buff_image(t_data *data);
// proc_mlx_err.c
void			proc_mlx_err(t_data *data, int err_code, void *param);
// proc_mlx_init.c
void			proc_mlx_init(t_data *data);
// proc_mlx_load_sprite.c
void			after_mlx_xpm_file_to_image(t_data *data, int img_code);
void			proc_mlx_load_suicune(t_data *data, int *trash);
void			proc_mlx_load_sprite(t_data *data);
// proc_mlx_new_window.c
void			proc_mlx_new_window(t_data *data);
// put_images_to_buff.c
unsigned int	get_pixel_from_image(t_img *img_data, int x, int y);
void			put_pixel_to_buff(t_img *buff_data,
					int pixel_x, int pixel_y, unsigned int pixel);
void			put_image_to_buff(t_data *data, int img_code, int x, int y);
void			put_suicune_to_buff(t_data *data, int x, int y);
void			put_images_to_buff(t_data *data, int x, int y);
// quit_program.c
void			quit_program(t_data *data);
// read_map_file.c
void			proc_gnl_err(char **map, int return_code);
void			cpy_old_map(char **dst, char **src, int n);
char			**malloc_new_map(char **map, int line, int secured_line);
void			close_map_file(int fd, t_map *map_data);
void			read_map_file(int fd, t_map *map_data);
// refresh_display.c
void			refresh_display(t_data *data);
// refresh_map.c
void			set_current_and_dst_tile(
					t_data *data, char **current, char **dst);
int				check_tile_walkable(t_data *data, char *dst_tile);
void			change_tile(t_data *data, char *current_tile, char *dst_tile);
void			change_player_pos(t_data *data);
void			refresh_map(t_data *data);

#endif
