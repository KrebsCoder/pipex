/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 04:37:09 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/02/08 03:53:39 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex(int argc, char *argv[], char **envp)
{
	t_data data;

	if (argc != 5)
		return (EXIT_FAILURE);
	else if (argc == 5)
	{
		init_values(&data, argc, argv, envp);
		open_files(&data);
		pipes(&data, argv, envp);
	}
	return (EXIT_SUCCESS);
}
