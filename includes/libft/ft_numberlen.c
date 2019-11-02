/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numberlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabirov <mkabirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 14:22:32 by mkabirov          #+#    #+#             */
/*   Updated: 2019/08/07 17:07:53 by mkabirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_numberlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < len)
		len = len + 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}
