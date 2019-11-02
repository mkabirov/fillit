/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabirov <mkabirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 15:04:31 by mkabirov          #+#    #+#             */
/*   Updated: 2019/08/03 15:12:46 by mkabirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void				ft_putnbr_fd(int n, int fd)
{
	unsigned int	un;
	char			c;

	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	un = (unsigned int)n;
	if (un < 10)
	{
		c = un + '0';
		write(fd, &c, 1);
	}
	if (un >= 10)
	{
		ft_putnbr_fd(un / 10, fd);
		ft_putnbr_fd(un % 10, fd);
	}
}
