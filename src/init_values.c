/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:40:42 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/02/04 00:35:36 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_values(t_data *data, int argc, char *argv[], char **envp)
{
	data->file_in.arg_v = argv[1];
	data->file_out.arg_v = argv[4];
	data->envp = envp;
	data->cmd_qnt = argc - 3;
}
