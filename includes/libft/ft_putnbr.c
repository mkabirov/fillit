/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabirov <mkabirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 13:59:17 by mkabirov          #+#    #+#             */
/*   Updated: 2019/08/03 14:54:53 by mkabirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void				ft_putnbr(int n)
{
	unsigned int	un;
	char			c;

	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	un = (unsigned int)n;
	if (un < 10)
	{
		c = un + '0';
		write(1, &c, 1);
	}
	if (un >= 10)
	{
		ft_putnbr(un / 10);
		ft_putnbr(un % 10);
	}
}
