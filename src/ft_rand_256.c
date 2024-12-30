/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand_256.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 09:42:59 by akyoshid          #+#    #+#             */
/*   Updated: 2024/12/30 09:44:54 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// return random number 0 ~ 255
// if open() fails, return -1
// if close() fails, return -2
// if read() fails, return -3
int	ft_rand_256(void)
{
	int				fd;
	int				read_rv;
	unsigned char	random_byte;

	fd = open("/dev/urandom", O_RDONLY);
	if (fd == -1)
		return (RAND_ERR_OPEN);
	read_rv = read(fd, &random_byte, 1);
	if (read_rv == -1)
	{
		if (close(fd) == -1)
			return (RAND_ERR_CLOSE);
		return (RAND_ERR_READ);
	}
	if (close(fd) == -1)
		return (RAND_ERR_CLOSE);
	return ((int)random_byte);
}

void	proc_rand_err(t_data *data, int rand)
{
	mlx_loop_end(data->mlx);
	if (rand == RAND_ERR_OPEN)
		perror("open");
	else if (rand == RAND_ERR_READ)
		perror("read");
	else if (rand == RAND_ERR_CLOSE)
		perror("close");
}
