/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 02:14:32 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/02/14 01:44:35 by lkrebs-l         ###   ########.fr       */
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
	if (ft_strchr(argv, SINGLE_QUOTE))
		treat_space(data, argv);
	else
		data->cmd = ft_split(argv, SPACE);
}

int	treat_space(t_data *data, char *argv)
{
	char	*pos1;
	char	*pos2;
	char	caracter;
	int		i;

	pos1 = ft_strchr(argv, SINGLE_QUOTE);
	caracter = pos1[1];
	pos2 = ft_strrchr(argv, SINGLE_QUOTE);
	if (pos1 == pos2)
	{
		data->cmd = ft_split(argv, SPACE);
		return (EXIT_SUCCESS);
	}
	else
	{
		i = 0;
		while (pos1[i])
		{
			pos1[i] = ';';
			i++;
		}
		data->cmd = ft_split(argv, SPACE);
		data->cmd[2][0] = caracter;
	}
	return (EXIT_SUCCESS);
}

void	exec_cmd(t_data *data, char *argv, char **envp)
{
	char	*cmd;

	parse_env(data, envp);
	parse_args(data, argv);
	cmd = path_bin(data);
	if (!cmd)
	{
		errno = 22;
		perror(data->cmd[0]);
		free_all(data);
		exit(127);
	}
	if (execve(cmd, data->cmd, envp) == -1)
	{
		free_all(data);
		exit(1);
	}
}
