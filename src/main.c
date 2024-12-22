/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 09:16:59 by akyoshid          #+#    #+#             */
/*   Updated: 2024/12/22 09:42:19 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// err_code == 0 : Invaild number of arguments
// err_code == 1 : open() failed
// err_code == 2 : malloc() failed
void	proc_err(int err_code, void *param)
{
	if (err_code == 0)
		ft_printf("main: Invalid number of arguments: Expected 2 arguments\n");
	if (err_code == 1)
		perror("open");
	if (err_code == 2)
		perror("malloc");
	exit(EXIT_FAILURE);
}

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
	if (return_code == GNL_FAILURE_BUFFER_SIZE)
		ft_printf("get_next_line: Invalid BUFFER_SIZE\n");
	else if (return_code == GNL_FAILURE_FD)
		ft_printf("get_next_line: Invalid fd\n");
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

int	open_map_file(char *map_file)
{
	int		fd;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		proc_err(1, NULL);
	return (fd);
}

int	main(int argc, char *argv[])
{
	int		fd;
	t_map	map_data;

	if (argc != 2)
		proc_err(0, NULL);
	fd = open_map_file(argv[1]);
	map_data.map = read_map_file(fd, NULL, 0, 64);
	free_map(map_data.map);
	return (0);
}
