/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checktetris.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabirov <mkabirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 16:34:59 by yehuang           #+#    #+#             */
/*   Updated: 2019/10/13 12:33:08 by mkabirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		check_lines_columns(char (*data)[21], int box, int chars)
{
	if (data[box][chars] == '\n' && data[box][chars + 1] == '\n'
		&& data[box][chars + 2] == '\0')
		return (-4);
	if ((chars + 1) % 5 == 0 && data[box][chars] != '\n' && data[box][20])
		return (-3);
	return (1);
}

int		check_hash_points(int hashes, int points)
{
	if (hashes != 4)
		return (-6);
	if (points != 12)
		return (-1);
	return (1);
}

int		checktetris(char data[26][21])
{
	int box;
	int chars;
	int points;
	int hashes;

	box = -1;
	while (++box < 26)
	{
		points = 0;
		hashes = 0;
		chars = -1;
		while (++chars < 21)
			if ((check_lines_columns(data, box, chars)) < 0)
				return (-5);
			else if (data[box][chars] == '.')
				points++;
			else if (data[box][chars] == '#')
				hashes++;
		if ((check_hash_points(hashes, points)) < 0)
			return (-1);
		if (data[box][chars] == '\0')
			break ;
	}
	return (check_figure_valid(data));
}
