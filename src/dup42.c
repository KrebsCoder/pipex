/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup42.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 04:22:48 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/02/09 20:50:22 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	dup42(t_data *data, int fd, int std)
{
	int	check;

	check = dup2(fd, std);
	close(fd);
	if (check == -1)
		msg_error(data);
}
