/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 04:17:26 by akyoshid          #+#    #+#             */
/*   Updated: 2024/12/23 04:18:08 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	proc_err(int err_code, void *param)
{
	if (err_code == SL_ERR_NUM_OF_ARG)
		ft_fprintf(STDERR_FILENO,
			"main: Invalid number of arguments: Expected 2 arguments\n");
	if (err_code == SL_ERR_OPEN)
		perror("open");
	exit(EXIT_FAILURE);
}
