/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 06:37:47 by akyoshid          #+#    #+#             */
/*   Updated: 2024/12/23 06:38:03 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_argc(int argc)
{
	if (argc != 2)
		proc_err(SL_ERR_NUM_OF_ARG, NULL);
}

void	check_file_ext(char *map_file)
{
	int	len;

	len = ft_strlen(map_file);
	if (len < 4
		|| map_file[len - 4] != '.' || map_file[len - 3] != 'b'
		|| map_file[len - 2] != 'e' || map_file[len - 1] != 'r')
		proc_err(SL_ERR_FILE_EXT, NULL);
}

void	check_arg(int argc, char *map_file)
{
	check_argc(argc);
	check_file_ext(map_file);
}
