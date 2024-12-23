/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:24:44 by akyoshid          #+#    #+#             */
/*   Updated: 2024/12/23 09:53:55 by akyoshid         ###   ########.fr       */
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
# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"
# include "../libft/inc/get_next_line_bonus.h"

# define SL_ERR_NUM_OF_ARG 0
# define SL_ERR_FILE_EXT 1
# define SL_ERR_OPEN 2
# define SL_ERR_MAP 3

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
void	check_component_loop(t_map *map_data, int *e_count, int *p_count);
void	check_component(t_map *map_data);
//check_map.c
void	proc_map_err(t_map *map_data, void *param);
void	check_rectangular(t_map *map_data);
void	check_wall(t_map *map_data);
// open_map_file.c
int	open_map_file(char *map_file);
// proc_err.c
void	proc_err(int err_code, void *param);
// read_map_file.c
void	free_map(char **map);
void	proc_gnl_err(char **map, int return_code);
void	map_cpy(char **dst, char **src, int n);
char	**malloc_new_map(char **map, int line, int secured_line);
void	read_map_file(int fd, t_map *map_data);

#endif
