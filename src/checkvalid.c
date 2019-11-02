/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkvalid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabirov <mkabirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:49:10 by mkabirov          #+#    #+#             */
/*   Updated: 2019/10/13 12:24:38 by mkabirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		check_hash_position(char (*data)[21], int i, int k)
{
	if (data[i][k] == '#' && data[i][k + 1] == '#')
	{
		if (data[i][k - 5] != '#' && data[i][k - 4] != '#'
		&& data[i][k - 1] != '#' && data[i][k + 2] != '#'
		&& data[i][k + 5] != '#' && data[i][k + 6] != '#')
			return (-22);
	}
	if (data[i][k] == '#' && data[i][k + 5] == '#')
	{
		if (data[i][k - 5] != '#' && data[i][k - 1] != '#'
		&& data[i][k + 1] != '#' && data[i][k + 4] != '#'
		&& data[i][k + 6] != '#' && data[i][k + 10] != '#')
			return (-55);
	}
	return (1);
}

int		check_onehash(char (*data)[21], int i, int j)
{
	if (data[i][j] == '#')
	{
		if (data[i][j - 1] != '#' &&
		data[i][j + 1] != '#' && data[i][j + 5] != '#'
		&& data[i][j - 5] != '#')
			return (-1);
	}
	return (1);
}

int		check_figure_valid(char data[26][21])
{
	int box;
	int chars;

	box = -1;
	while (++box < 26)
	{
		chars = -1;
		while (++chars < 20)
		{
			if ((check_onehash(data, box, chars)) < 0)
				return (-1);
		}
		chars = -1;
		while (++chars < 20)
		{
			if ((check_hash_position(data, box, chars)) < 0)
				return (-7);
		}
	}
	return (1);
}
