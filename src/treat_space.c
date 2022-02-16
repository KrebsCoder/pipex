/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:20:15 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/02/16 03:05:45 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static	int	ft_find_pos(char *cmd_dup, int index)
{
	while (cmd_dup[index] != SINGLE_QUOTE)
		index++;
	return (index);
}

void	treat_space(t_data *data, char *argv)
{
	char	*cmd_dup;
	int		pos1;
	int		pos2;
	char	*test;
	int		i;

	cmd_dup = ft_strdup(argv);
	pos1 = ft_find_pos(cmd_dup, 0);
	pos2 = ft_find_pos(cmd_dup, pos1 + 1);
	if (cmd_dup[pos2 + 1] == '\0')
		i = 2;
	else
		i = 1;
	test = ft_substr(cmd_dup, pos1 + 1, pos2 - pos1 - 1);
	while (pos1 <= pos2)
	{
		cmd_dup[pos1] = 'x';
		pos1++;
	}
	data->cmd = ft_split(cmd_dup, SPACE);
	data->cmd[i] = ft_strdup(test);
	free(cmd_dup);
	free(test);
	cmd_dup = NULL;
	test = NULL;
}
