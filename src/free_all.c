/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 05:51:28 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/02/08 01:57:13 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_all(t_data data)
{
	free_mat(data.bin);
	free_mat(data.cmd);
	free_mat(data.envp);
}

static	void	free_mat(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
	{
		free(mat[i]);
		i++;
	}
	free(mat);
	mat = NULL;
}
