/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabirov <mkabirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 19:19:11 by mkabirov          #+#    #+#             */
/*   Updated: 2019/07/25 15:08:41 by mkabirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int len;

	len = 0;
	while (s[len])
		len++;
	if (c == '\0')
		return ((char *)s + len);
	while (len--)
		if (*(s + len) == c)
			return ((char *)(s + len));
	return (0);
}
