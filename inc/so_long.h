/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:24:44 by akyoshid          #+#    #+#             */
/*   Updated: 2024/12/24 15:38:12 by akyoshid         ###   ########.fr       */
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
# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"
# include "../libft/inc/get_next_line_bonus.h"

# define SL_ERR_PARAM 0
# define SL_ERR_NUM_OF_ARG 1
# define SL_ERR_FILE_EXT 2
# define SL_ERR_OPEN 3
# define SL_ERR_MALLOC 4
# define SL_ERR_CLOSE 5

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

// check_arg.c
void	check_argc(int argc);
void	check_file_ext(char *map_file);
void	check_arg(int argc, char *map_file);
// check_compo.c
void	check_invalid_component(t_map *map_data, int *e_count, int *p_count);
void	check_component(t_map *map_data);
//check_map.c
void	check_rectangular(t_map *map_data);
void	check_wall(t_map *map_data);
// map_utils.c
void	proc_map_err(char **map_1, char **map_2, int err_code, void *param);
void	free_map(char **map);
// open_map_file.c
int	open_map_file(char *map_file);
// proc_err.c
void	proc_err(int err_code, void *param);
// read_map_file.c
void	proc_gnl_err(char **map, int return_code);
void	cpy_old_map(char **dst, char **src, int n);
char	**malloc_new_map(char **map, int line, int secured_line);
void	close_map_file(int fd, t_map *map_data);
void	read_map_file(int fd, t_map *map_data);


#endif
