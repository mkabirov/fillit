/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabirov <mkabirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 20:39:54 by mkabirov          #+#    #+#             */
/*   Updated: 2019/08/07 19:41:58 by mkabirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void				*ft_memcpy(void *restrict dst, const void *restrict src,
size_t n)
{
	unsigned char	*d;
	const char		*s;

	d = dst;
	s = src;
	if (dst == src || n == 0)
		return (dst);
	while (n)
	{
		*d++ = *s++;
		n--;
	}
	return (dst);
}
