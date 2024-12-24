/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 04:19:41 by akyoshid          #+#    #+#             */
/*   Updated: 2024/12/24 15:40:12 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	proc_gnl_err(char **map, int return_code)
{
	free_map(map);
	ft_fprintf(STDERR_FILENO, "Error\n");
	if (return_code == GNL_FAILURE_BUFFER_SIZE)
		ft_fprintf(STDERR_FILENO, "get_next_line: Invalid BUFFER_SIZE\n");
	else if (return_code == GNL_FAILURE_FD)
		ft_fprintf(STDERR_FILENO, "get_next_line: Invalid fd\n");
	else if (return_code == GNL_FAILURE_MALLOC)
		perror("malloc");
	else if (return_code == GNL_FAILURE_READ)
		perror("read");
	exit(EXIT_FAILURE);
}

void	cpy_old_map(char **dst, char **src, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
}

char	**malloc_new_map(char **map, int line, int secured_line)
{
	char	**new_map;

	new_map = (char **)malloc(sizeof(char *) * (secured_line + 1));
	if (new_map == NULL)
		proc_map_err(map, NULL, SL_ERR_MALLOC, NULL);
	if (line != 0)
	{
		cpy_old_map(new_map, map, line);
		free(map);
	}
	return (new_map);
}

void	close_map_file(int fd, t_map *map_data)
{
	if (close(fd) == -1)
		proc_map_err(map_data->map, NULL, SL_ERR_CLOSE, NULL);
}

void	read_map_file(int fd, t_map *map_data)
{
	int	line;
	int	secured_line;
	int	gnl_return_code;

	line = 0;
	secured_line = 64;
	while (1)
	{
		map_data->map = malloc_new_map(map_data->map, line, secured_line);
		while (line < secured_line)
		{
			map_data->map[line] = get_next_line(fd, &gnl_return_code);
			if (map_data->map[line] == NULL)
				break ;
			line++;
		}
		if (line < secured_line && map_data->map[line] == NULL)
			break ;
		map_data->map[line] = NULL;
		secured_line += 64;
	}
	if (gnl_return_code != GNL_SUCCESS_FIN)
		proc_gnl_err(map_data->map, gnl_return_code);
	close_map_file(fd, map_data);
	map_data->y_count = line;
}
