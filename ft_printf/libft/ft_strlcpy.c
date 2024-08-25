/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:05:26 by jrubio-m          #+#    #+#             */
/*   Updated: 2023/09/27 17:58:02 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	c;

	c = 0;
	if (n == 0)
		return (ft_strlen(src));
	while (src[c] != '\0' && c < n - 1)
	{
		dst[c] = src[c];
		c++;
	}
	dst[c] = '\0';
	return (ft_strlen(src));
}
