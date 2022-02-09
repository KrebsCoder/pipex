/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 19:18:40 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/02/09 20:46:45 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipes(t_data *data, char *argv[], char **envp)
{
	if (pipe(data->fd) == -1)
	{
		msg_error(data);
		return (EXIT_FAILURE);
	}
	dup42(data, data->files.in_fd, STDIN_FILENO);
	data->pid1 = fork();
	if (data->pid1 == -1)
	{
		msg_error(data); 
		return (EXIT_FAILURE);
	}
	if (data->pid1 == 0)
	{
		dup42(data, data->fd[1], STDOUT_FILENO);
		exec_cmd(data, argv[2], envp);
	}
	waitpid(data->pid1,  &data->exit_status, WNOHANG);
	data->pid2 = fork();
	if (data->pid2 == 0) 
	{
		dup42(data, data->fd[0], STDIN_FILENO);
		close(data->fd[1]);
		dup42(data, data->files.out_fd, STDOUT_FILENO);
		exec_cmd(data, argv[3], envp);
	}
	waitpid(data->pid2, &data->exit_status, WNOHANG);
	//free_all(data);
	return (WIFEXITED(data->exit_status));
}
