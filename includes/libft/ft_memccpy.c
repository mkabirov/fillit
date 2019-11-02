/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabirov <mkabirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 22:50:34 by mkabirov          #+#    #+#             */
/*   Updated: 2019/07/27 22:18:59 by mkabirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void				*ft_memccpy(void *restrict dst, const void *restrict src,
int c, size_t n)
{
	unsigned char	*d;
	const char		*s;
	size_t			i;

	d = dst;
	s = src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		if (d[i] == (unsigned char)c)
			return ((void*)(dst + i + 1));
		i++;
	}
	return (0);
}
