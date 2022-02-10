/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:40:42 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/02/04 23:50:33 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_values(t_data *data, int argc, char *argv[], char **envp)
{
	data->files.infile = argv[1];
	data->files.outfile = argv[4];
	data->envp = envp;
	data->cmd_qnt = argc - 3;
}
