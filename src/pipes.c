/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 19:18:40 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/02/10 01:26:27 by lkrebs-l         ###   ########.fr       */
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
	if (cmd_infile(data, argv, envp) == 1)
		return (EXIT_FAILURE);
	waitpid(data->pid1, &data->exit_status, 0);
	close(data->fd[1]);
	if (cmd_outfile(data, argv, envp) == 1)
		return (EXIT_FAILURE);
	waitpid(data->pid2, &data->exit_status, 0);
	return (WEXITSTATUS(data->exit_status));
}

int	cmd_infile(t_data *data, char *argv[], char **envp)
{
	data->pid1 = fork();
	if (data->pid1 == -1)
	{
		msg_error(data);
		return (EXIT_FAILURE);
	}
	if (data->pid1 == 0)
	{
		dup42(data, data->files.in_fd, STDIN_FILENO);
		dup42(data, data->fd[1], STDOUT_FILENO);
		exec_cmd(data, argv[2], envp);
	}
	return (EXIT_SUCCESS);
}

int	cmd_outfile(t_data *data, char *argv[], char **envp)
{
	data->pid2 = fork();
	if (data->pid2 == -1)
	{
		msg_error(data);
		return (EXIT_FAILURE);
	}
	if (data->pid2 == 0)
	{
		dup42(data, data->fd[0], STDIN_FILENO);
		dup42(data, data->files.out_fd, STDOUT_FILENO);
		exec_cmd(data, argv[3], envp);
	}
	return (EXIT_SUCCESS);
}
