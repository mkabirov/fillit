/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabirov <mkabirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 14:13:33 by mkabirov          #+#    #+#             */
/*   Updated: 2019/07/25 21:48:30 by mkabirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char				*ft_strncat(char *restrict s1, const char *restrict s2,
size_t n)
{
	int				i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		++i;
	}
	while (s2[j] && j < n)
	{
		s1[i] = s2[j];
		i++;
		++j;
	}
	s1[i] = '\0';
	return (s1);
}
