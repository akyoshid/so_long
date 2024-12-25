/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 04:17:26 by akyoshid          #+#    #+#             */
/*   Updated: 2024/12/25 07:24:01 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	proc_err(int err_code, void *param)
{
	ft_fprintf(STDERR_FILENO, "Error\n");
	if (err_code == SL_ERR_PARAM)
		ft_fprintf(STDERR_FILENO, "%s", (char *)param);
	else if (err_code == SL_ERR_OPEN)
		perror("open");
	else if (err_code == SL_ERR_MALLOC)
		perror("malloc");
	else if (err_code == SL_ERR_CLOSE)
		perror("close");
	exit(EXIT_FAILURE);
}
