/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 00:40:23 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/02/14 00:40:47 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strrchr(const char *string, int c)
{
	size_t	lenght;

	lenght = ft_strlen(string) + 1;
	while (lenght--)
	{
		if (string[lenght] == (unsigned char)c)
			return ((char *) string + lenght);
	}
	return (NULL);
}
