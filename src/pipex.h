/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 23:08:11 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/02/03 07:15:08 by lkrebs-l         ###   ########.fr       */
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

typedef struct s_data
{
	int		fd[2];
	pid_t	pid1;
	int		pid2;
	char	file_in;
	char	file_out;
}	t_data;

int	pipex(int argc, char *argv[], char *envp);
int	open_files(t_data *data, char *argv[]);
int	close_files(t_data *data);

#endif