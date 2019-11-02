/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabirov <mkabirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 22:08:47 by mkabirov          #+#    #+#             */
/*   Updated: 2019/10/10 16:22:35 by mkabirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	unsigned int *mem;

	mem = (unsigned int *)malloc(size);
	if (!mem)
		return (NULL);
	else
		ft_bzero(mem, size);
	return (mem);
}
