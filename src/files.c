/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 07:06:38 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/02/03 07:28:59 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_files(t_data *data, char *argv)
{
	data->file_in = open(argv[1], O_RDONLY);
	if (data->file_in < 1)
	{
		return (EXIT_FAILURE);
		// call error function
	}
		
	data->file_out = open(argv[4], O_WRONLY | O_CREAT, 0777);
	if (data->file_out < 1)
	{
		return (EXIT_FAILURE);
		// call error function
	}
	return (EXIT_SUCCESS);
}

void	close_files(t_data *data)
{
	close(data->file_in);
	close(data->file_out);
}
