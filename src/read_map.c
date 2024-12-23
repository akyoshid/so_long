/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 04:19:41 by akyoshid          #+#    #+#             */
/*   Updated: 2024/12/23 04:44:56 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (map != NULL)
	{
		while (map[i] != NULL)
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
}

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

void	map_cpy(char **dst, char **src, int n)
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
		proc_gnl_err(map, GNL_FAILURE_MALLOC);
	map_cpy(new_map, map, line);
	free(map);
	return (new_map);
}

char	**read_map_file(int fd, char **map, int line, int secured_line)
{
	int	gnl_return_code;

	while (1)
	{
		map = malloc_new_map(map, line, secured_line);
		while (line < secured_line)
		{
			map[line] = get_next_line(fd, &gnl_return_code);
			if (map[line] == NULL)
				break ;
			line++;
		}
		if (line < secured_line && map[line] == NULL)
			break ;
		map[line] = NULL;
		secured_line += 64;
	}
	if (gnl_return_code != GNL_SUCCESS_FIN)
		proc_gnl_err(map, gnl_return_code);
	return (map);
}