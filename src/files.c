/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 07:06:38 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/02/04 18:43:27 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_files(t_data *data)
{
	data->files.in_fd = open(data->files.infile, O_RDONLY);
	data->files.out_fd = open(data->files.outfile, O_WRONLY | O_CREAT, 0777);
	if (data->files.in_fd < 1 || data->files.out_fd < 1)
	{
		//handle_error(data, 1);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	close_files(t_data *data)
{
	close(data->files.in_fd);
	close(data->files.out_fd);
}
