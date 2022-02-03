/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 04:38:53 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/02/03 04:40:45 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp)
{
	if (argc != 5)
		return(EXIT_FAILURE);
	else
		pipex(argc, argv, envp);
	return (EXIT_SUCCESS);
}