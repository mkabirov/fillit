/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabirov <mkabirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:33:28 by mkabirov          #+#    #+#             */
/*   Updated: 2019/08/08 13:05:52 by mkabirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char				*ft_strtrim(char const *s)
{
	unsigned int	start;
	unsigned int	i;
	unsigned int	len;
	size_t			size;
	char			*str;

	i = 0;
	start = 0;
	if (!s)
		return (NULL);
	size = ft_strlen(s);
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	start = i;
	len = ft_strlen(s);
	while (len-- && s[i] && s[len] && (s[len] == ' ' || s[len] == '\n'
	|| s[len] == '\t'))
		size = len - start;
	str = (ft_strnew(size));
	if (!str)
		return (NULL);
	return (ft_strsub(s, start, size));
}
