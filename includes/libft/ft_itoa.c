/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabirov <mkabirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 14:37:50 by mkabirov          #+#    #+#             */
/*   Updated: 2019/08/04 13:35:40 by mkabirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_itoa(int n)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	j = ft_numberlen(n);
	str = (char *)malloc(sizeof(char) * (j + 1));
	if (!str)
		return (NULL);
	str[j] = 0;
	if (n < 0)
	{
		str[0] = '-';
		n = -1 * n;
		i = i + 1;
	}
	while (i < j--)
	{
		str[j] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
