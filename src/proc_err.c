/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 04:17:26 by akyoshid          #+#    #+#             */
/*   Updated: 2024/12/24 14:04:15 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	proc_err(int err_code, void *param)
{
	ft_fprintf(STDERR_FILENO, "Error\n");
	if (err_code == SL_ERR_PARAM)
		ft_fprintf(STDERR_FILENO, "%s", (char *)param);
	if (err_code == SL_ERR_NUM_OF_ARG)
		ft_fprintf(STDERR_FILENO,
			"check_argc: Invalid number of arguments: Expected 2 arguments\n");
	else if (err_code == SL_ERR_FILE_EXT)
		ft_fprintf(STDERR_FILENO,
			"check_file_ext: Invalid filename extention: Expected .ber\n");
	else if (err_code == SL_ERR_OPEN)
		perror("open");
	else if (err_code == SL_ERR_MALLOC)
		perror("malloc");
	exit(EXIT_FAILURE);
}
