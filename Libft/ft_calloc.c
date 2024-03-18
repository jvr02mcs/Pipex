/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:54:40 by codespace         #+#    #+#             */
/*   Updated: 2023/09/27 19:18:30 by codespace        ###   ########.fr       */
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
