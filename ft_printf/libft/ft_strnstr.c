/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:15:12 by jrubio-m          #+#    #+#             */
/*   Updated: 2023/09/28 20:11:55 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	size_t	c;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < n && n > 0)
	{
		c = 0;
		while (big[i + c] == little[c] && little[c] != '\0' && i + c < n)
			c++;
		if (little[c] == '\0')
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
