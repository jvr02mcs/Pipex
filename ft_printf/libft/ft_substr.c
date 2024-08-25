/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:15:43 by jrubio-m          #+#    #+#             */
/*   Updated: 2023/10/03 17:15:53 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	c;
	size_t	s_l;

	s_l = ft_strlen(s);
	if (start >= s_l || len == 0)
		return (ft_strdup(""));
	if (len >= s_l - start)
		len = s_l - start;
	sub = (char *)malloc(sizeof(*s) * (len + 1));
	if (!sub)
		return (NULL);
	c = 0;
	i = start;
	while (s[i] && c < len)
	{
		sub[c] = s[i];
		c++;
		i++;
	}
	sub[c] = '\0';
	return (sub);
}
