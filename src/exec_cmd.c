/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 02:14:32 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/02/05 03:16:38 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*path_bin(t_data *data, char *argv)
{
	int		i;
	int		check;
	char	*path;
	char	*cmd;
	i = 0;
	while (data->bin[i])
	{
		path = ft_strjoin(data->bin[i], '/');
		cmd = ft_strjoin(path, argv);
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

char	exec_cmd(t_data *data, char *argv)
{
	char *cmd;
	cmd = path_bin(data, argv);
}