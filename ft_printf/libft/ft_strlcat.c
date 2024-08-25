/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:03:31 by jrubio-m          #+#    #+#             */
/*   Updated: 2023/09/27 17:35:04 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	c;
	size_t	i;

	c = 0;
	i = 0;
	while (dst[c] && c < n)
		c++;
	while ((src[i]) && ((c + i + 1) < n))
	{
		dst[c + i] = src[i];
		i++;
	}
	if (c != n)
		dst[c + i] = '\0';
	return (c + ft_strlen(src));
}
