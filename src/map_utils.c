/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 05:53:16 by akyoshid          #+#    #+#             */
/*   Updated: 2024/12/24 15:38:03 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	proc_map_err(char **map_1, char **map_2, int err_code, void *param)
{
	free_map(map_1);
	free_map(map_2);
	proc_err(err_code, param);
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
