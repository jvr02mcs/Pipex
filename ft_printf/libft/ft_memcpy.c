/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:04:57 by jrubio-m          #+#    #+#             */
/*   Updated: 2023/10/03 16:43:02 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	size_t		i;

	d = dst;
	s = src;
	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst == NULL)
		d[i] = '\0';
	while (i < n)
	{
		if (s == NULL)
			d[i] = '\0';
		else
			d[i] = s[i];
		i++;
	}
	return (dst);
}
