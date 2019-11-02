/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabirov <mkabirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 20:40:38 by yehuang           #+#    #+#             */
/*   Updated: 2019/10/13 12:55:36 by mkabirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char	**save2darray(char *buf, int *count)
{
	char	**shapes;
	int		i;
	int		cur_char;

	shapes = (char**)ft_memalloc(27 * sizeof(*shapes));
	i = 0;
	while (i < 26)
		shapes[i++] = ft_strnew(16);
	i = -1;
	cur_char = 0;
	while (buf[++i])
	{
		if (buf[i] != '\n')
		{
			if (buf[i] == '.')
				shapes[cur_char / 16][cur_char % 16] = buf[i];
			if (buf[i] == '#')
				shapes[cur_char / 16][cur_char % 16] = 'A' + ((cur_char / 16));
			cur_char++;
		}
	}
	*count = cur_char / 16;
	return (shapes);
}

int		read_tetris(const int fd, char *buff)
{
	int rd;

	rd = read(fd, buff, 550);
	buff[rd] = '\0';
	return (1);
}

int		open_read_copy_check(char **file, char *buff, char (*data)[21])
{
	int		fd;
	int		box;
	int		chars;
	int		i;
	int		checktetrim;

	box = 0;
	i = 0;
	fd = open(*file, O_RDONLY);
	ft_bzero(buff, sizeof(buff));
	read_tetris(fd, buff);
	while (box < 26 && buff[i])
	{
		chars = 0;
		while (chars < 21 && buff[i])
		{
			data[box][chars] = buff[i];
			chars++;
			i++;
		}
		box++;
	}
	close(fd);
	return (checktetrim = checktetris(data));
}

int		main(int ac, char **av)
{
	char	buff[551];
	char	data[26][21];
	char	**realshape;
	int		checktetrim;
	int		count;

	checktetrim = 0;
	count = 0;
	if (ac == 2)
		checktetrim = open_read_copy_check(&av[1], buff, data);
	if (checktetrim == 1)
	{
		realshape = save2darray(buff, &count);
		solve(realshape, count);
		count = -1;
		while (++count < 27)
			free(realshape[count]);
		free(realshape);
	}
	else
		ft_putstr("error\n");
	return (0);
}
