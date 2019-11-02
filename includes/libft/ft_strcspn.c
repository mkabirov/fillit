/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabirov <mkabirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 21:52:33 by mkabirov          #+#    #+#             */
/*   Updated: 2019/08/07 00:45:02 by mkabirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strcspn(const char *s, const char *charset)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
	{
		if (ft_strchr(charset, s[i]) != 0)
			break ;
		i++;
	}
	return (i);
}
