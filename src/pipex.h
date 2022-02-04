/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 23:08:11 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/02/04 21:38:00 by lkrebs-l         ###   ########.fr       */
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
	int		in_fd;
	int		out_fd;
	char	*infile;
	char	*outfile;
} t_file;

typedef struct s_data
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;
	char	**envp;
	char	*path;
	int		cmd_qnt;
	t_file files;
}	t_data;

int		pipex(int argc, char *argv[], char **envp);
int		open_files(t_data *data);
void	close_files(t_data *data);
int		exec_cmd(t_data *data, int argc, char **envp);
void	init_values(t_data *data, int argc, char *argv[], char **envp);
/* void	handle_error(int signal, t_data *data); */
#endif