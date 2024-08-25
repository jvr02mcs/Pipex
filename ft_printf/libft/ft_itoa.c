/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:30:33 by jrubio-m          #+#    #+#             */
/*   Updated: 2023/10/10 21:30:34 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int n)
{
	int	i;

	i = 1;
	while (n / 10 != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static char	*itoa_p(int n, int l_dgts)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (l_dgts + 1));
	if (!str)
		return (NULL);
	str[l_dgts] = '\0';
	l_dgts--;
	while (l_dgts >= 0)
	{
		str[l_dgts] = n % 10 + '0';
		n /= 10;
		l_dgts--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		l_dgts;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	l_dgts = ft_count(n);
	if (n < 0)
	{
		str = itoa_p(-n, l_dgts + 1);
		if (!str)
			return (NULL);
		str[0] = '-';
	}
	else
	{
		str = itoa_p(n, l_dgts);
		if (!str)
			return (NULL);
	}
	return (str);
}
