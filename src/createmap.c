/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabirov <mkabirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 22:15:38 by mkabirov          #+#    #+#             */
/*   Updated: 2019/10/11 22:15:43 by mkabirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char	**emptymap(int const size)
{
	char	**map;
	int		i;
	int		j;

	if (!(map = (char **)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	map[size] = NULL;
	i = -1;
	while (++i < size)
	{
		if (!(map[i] = (char *)malloc(sizeof(char) * (size + 1))))
			return (NULL);
		map[i][size] = '\0';
	}
	i = -1;
	while (map[++i])
	{
		j = 0;
		while (j < size)
			map[i][j++] = '.';
	}
	return (map);
}
