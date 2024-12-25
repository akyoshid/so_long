/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:24:44 by akyoshid          #+#    #+#             */
/*   Updated: 2024/12/25 15:21:02 by akyoshid         ###   ########.fr       */
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

# define IMG_ENEMY 0
# define IMG_LOSER 1
# define IMG_MONSTER_BALL 2
# define IMG_PLAYER 3
# define IMG_EXIT_1 4
# define IMG_EXIT_2 5
# define IMG_EXIT_3 6
# define IMG_EXIT_4 7
# define IMG_EXIT_5 8
# define IMG_EXIT_6 9
# define IMG_EXIT_7 10
# define IMG_EXIT_8 11
# define IMG_TILE 12
# define IMG_TREE 13
# define IMG_COUNT 14

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
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	void	*img[14];
	t_map	map_data;
}			t_data;

// check_arg.c
void	check_argc(int argc);
void	check_file_ext(char *map_file);
void	check_arg(int argc, char *map_file);
// check_compo.c
void	check_invalid_component(t_map *map_data, int *e_count, int *p_count);
void	check_component(t_map *map_data);
// check_map.c
void	check_rectangular(t_map *map_data);
void	check_wall(t_map *map_data);
char	**cpy_map(t_map *map_data);
void	check_map(t_map *map_data);
// check_path_c.c
int		check_tile_c(char **map_cpy, int x, int y, int *count);
void	check_path_c_core(char **map_cpy, int y, int x, int *count);
void	check_path_c(t_map *map_data, char **map_cpy);
// check_path_e.c
int		check_tile_e(char **map_cpy, int x, int y, int *count);
void	check_path_e_core(char **map_cpy, int y, int x, int *count);
void	check_path_e(t_map *map_data, char **map_cpy);
// img_utils.c
void	free_img(t_data *data, int img_count);
// map_utils.c
void	proc_map_err(char **map_1, char **map_2, int err_code, void *param);
void	free_map(char **map);
// open_map_file.c
int		open_map_file(char *map_file);
// proc_err.c
void	proc_err(int err_code, void *param);
// proc_mlx_err.c
void	proc_mlx_err(t_data *data, int err_code, void *param);
// proc_mlx_init.c
void	proc_mlx_init(t_data *data);
// proc_mlx_load_sprite.c
void	proc_xpm_2_img_err(t_data *data, int img_code);
void	proc_mlx_load_suicune(t_data *data, int i);
void	proc_mlx_load_sprite(t_data *data);
// proc_mlx_new_window.c
void	proc_mlx_new_window(t_data *data);
// read_map_file.c
void	proc_gnl_err(char **map, int return_code);
void	cpy_old_map(char **dst, char **src, int n);
char	**malloc_new_map(char **map, int line, int secured_line);
void	close_map_file(int fd, t_map *map_data);
void	read_map_file(int fd, t_map *map_data);

#endif
