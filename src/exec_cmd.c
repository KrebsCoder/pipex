/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 19:18:40 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/02/04 21:41:39 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	exec_cmd(t_data *data, int argc, char **envp)
{
	if (pipe(data->fd) == -1)
		return (EXIT_FAILURE);
	dup2(data->files.in_fd, STDIN_FILENO);
	close(data->files.in_fd);
	data->pid1 = fork();
 	if (data->pid1 == -1)
	{
		close_files(data);
		perror("ERROR ->");
		return (EXIT_FAILURE);
	} 
	if (data->pid1 == 0)
	{
		dup2(data->fd[1], STDOUT_FILENO);
		close(data->fd[0]);
		close(data->fd[1]);
		execlp("cat", "cat", NULL); //<<-- just for testing 
		//execve(argv[2], &argv[1], envp);//  call function exec_cmd*
	}
	
	data->pid2 = fork();
	if (data->pid2 == 0) 
	{ 
		dup2(data->fd[0], STDIN_FILENO);
		dup2(data->files.out_fd, STDOUT_FILENO);
		close(data->fd[0]);
		close(data->fd[1]);
		execlp("wc", "wc", NULL);
		//execve(argv[3], &argv[1], envp);// call function exec_cmd
 	} 
	return (EXIT_SUCCESS);
}

/* int	parse_env(t_data *data, int argc, char *argv[], char **envp)
{
	
} */