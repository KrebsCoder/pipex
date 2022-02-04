/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 23:08:11 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/02/04 00:47:10 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include <stdio.h>

typedef struct s_file
{
	int		fd;
	char	*arg_v;
} t_file;

typedef struct s_data
{
	int		fd[2];
	pid_t	pid1;
	int		pid2;
	char	**envp;
	char	*path;
	int		cmd_qnt;
	t_file	file_in;
	t_file	file_out;
}	t_data;

int		pipex(int argc, char *argv[], char **envp);
int		open_files(t_data *data, char *argv[]);
void	close_files(t_data *data);
int		exec_cmd(t_data *data, char *argv[], char **envp);
void	init_values(t_data *data, int argc, char *argv[], char **envp);
/* void	handle_error(int signal, t_data *data); */
#endif