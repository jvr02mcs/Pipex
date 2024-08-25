/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:30:13 by jrubio-m          #+#    #+#             */
/*   Updated: 2023/10/10 21:30:15 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cnt(char const *s, char c)
{
	int	w;
	int	i;

	w = 0;
	i = 0;
	if (c < 0)
		return (0);
	if (s[0] != c)
		w++;
	while (s[i + 1] != '\0')
	{
		if (s[i] == c && s[i + 1] != c)
			w++;
		i++;
	}
	return (w);
}

static int	ft_wlen(const char *s, char c, int start)
{
	int	i;

	i = 0;
	while (s[start + i] != c && s[start + i] != '\0')
		i++;
	if (i == 0)
		i = 1;
	return (i);
}

void	*ft_freem(char **str, size_t iw)
{
	while (iw > 0)
	{
		free(str[iw]);
		iw--;
	}
	free(str[0]);
	free(str);
	return (NULL);
}

char	**ft_ifloc(char const *s, char c)
{
	char	**str;

	if (s[0] == '\0')
		str = malloc(sizeof(char *));
	else
		str = (char **)malloc(sizeof(char *) * (cnt(s, c) + 1));
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		iw;

	if (!s)
		return (NULL);
	str = ft_ifloc(s, c);
	if (!str)
		return (NULL);
	iw = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			str[iw] = ft_substr(s, i, ft_wlen(s, c, i));
			if (!str[iw++])
				return (ft_freem(str, iw - 1));
		}
		i = i + ft_wlen(s, c, i);
	}
	str[iw] = NULL;
	return (str);
}
