/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 01:38:17 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/02/05 01:50:26 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	*ft_memset(void *s, int c, size_t lenght)
{
	size_t	i;
	char	*buff;

	i = 0;
	buff = s;
	while (i < lenght)
		*(buff + i++) = c;
	return (s);
}

static void	ft_bzero(void *s, size_t n)
{
	ft_memset (s, 0, n);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
