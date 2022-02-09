/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 02:14:32 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/02/09 20:46:33 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*path_bin(t_data *data)
{
	int		i;
	int		check;
	char	*path;
	char	*cmd;

	i = 0;
	while (data->bin[i])
	{
		path = ft_strjoin(data->bin[i], "/");
		cmd = ft_strjoin(path, data->cmd[0]);
		check = access(cmd, F_OK);
		if (check == 0)
		{
			free(path);
			return (cmd);
		}
		free(path);
		free(cmd);
		i++;
	}
	return (NULL);
}

void	parse_args(t_data *data, char *argv)
{
	data->cmd = ft_split(argv, ' ');
}

void	exec_cmd(t_data *data, char *argv, char **envp)
{
	char	*cmd;

	parse_env(data, envp);
	parse_args(data, argv);
	cmd = path_bin(data);
	if (!cmd)
		free_all(data);
	if (execve(cmd, data->cmd, envp) == -1)
		free_all(data);
	execve(cmd, data->cmd, envp);
}
