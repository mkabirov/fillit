/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvefillit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabirov <mkabirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:49:26 by mkabirov          #+#    #+#             */
/*   Updated: 2019/10/13 13:08:34 by mkabirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	rmshape(char **map, char index, int mapsize)
{
	int i;
	int j;

	i = 0;
	while (i < mapsize)
	{
		j = 0;
		while (j < mapsize)
		{
			if (map[i][j] == ('A' + index))
				map[i][j] = '.';
			j++;
		}
		i++;
	}
}

int		tryshape(char *sp, char **map, int mc)
{
	int i;
	int fs;
	int s;

	fs = 0;
	s = ft_strlen(map[0]);
	while (sp[fs] == '.')
		fs++;
	i = 0;
	while (i < 16)
	{
		if (sp[i] != '.')
			if (mc / s + i / 4 - fs / 4 >= s || mc % s + i % 4 - fs % 4 >= s
			|| map[mc / s + i / 4 - fs / 4][mc % s + i % 4 - fs % 4] != '.')
				return (0);
		i++;
	}
	i = -1;
	while (sp[++i])
		if (sp[i] != '.')
			map[mc / s + i / 4 - fs / 4][mc % s + i % 4 - fs % 4] = sp[i];
	return (1);
}

int		trymap(char **shapes, char **map, int shapeindex, int shapecount)
{
	int	mapcoor;
	int mapsize;

	mapsize = ft_strlen(map[0]);
	mapcoor = 0;
	while (mapcoor < mapsize * mapsize)
	{
		if (tryshape(shapes[shapeindex], map, mapcoor) == 1)
		{
			if (shapeindex == shapecount - 1 ||
				trymap(shapes, map, shapeindex + 1, shapecount))
				return (1);
			rmshape(map, shapeindex, mapsize);
		}
		mapcoor++;
	}
	return (0);
}

void	free_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		ft_putendl(map[i]);
		free(map[i]);
		i++;
	}
	free(map);
}

void	solve(char **shapes, int shapecount)
{
	char	**map;
	int		mapsize;
	int		i;

	mapsize = 2;
	while (mapsize * mapsize < shapecount * 4)
		mapsize++;
	while (42)
	{
		map = emptymap(mapsize);
		if (trymap(shapes, map, 0, shapecount))
			break ;
		i = 0;
		while (i < mapsize)
			free(map[i++]);
		free(map);
		map = NULL;
		mapsize++;
	}
	free_map(map);
}
