/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabirov <mkabirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 19:28:13 by mkabirov          #+#    #+#             */
/*   Updated: 2019/10/13 12:34:46 by mkabirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../includes/libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/uio.h>
# include <sys/types.h>
# include "../libft/libft.h"
# include <string.h>

int		checktetris(char data[26][21]);
void	solve(char **shapes, int shapecount);
int		check_figure_valid(char data[26][21]);
char	**emptymap(int const size);

#endif
