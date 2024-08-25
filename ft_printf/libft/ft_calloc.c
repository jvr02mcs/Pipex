/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:05:04 by jrubio-m          #+#    #+#             */
/*   Updated: 2023/09/27 17:30:41 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t c, size_t n)
{
	size_t	t;
	void	*p;

	t = c * n;
	p = malloc(t);
	if (p != NULL)
		ft_memset(p, 0, t);
	return (p);
}
