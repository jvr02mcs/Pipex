/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:48:00 by jrubio-m          #+#    #+#             */
/*   Updated: 2024/04/17 15:55:01 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **e)
{
	int	i;

	i = 0;
	while (e[i])
	{
		if (ft_strncmp(e[i], "PATH=", 5) == 0)
			return (e[i] + 5);
		i++;
	}
	return (NULL);
}

void	error(int f, char *err, char *i)
{
	write(STDERR_FILENO, "pipex: ", 8);
	if (f == 1)
	{
		write(STDERR_FILENO, "Error in:\n", 11);
		write(STDERR_FILENO, err, ft_strlen(err));
	}
	else
	{
		write(1, err, ft_strlen(err));
		if (i)
			write(STDERR_FILENO, i, ft_strlen(i));
		write(STDERR_FILENO, "\n", 2);
	}
}

char	**ft_make_cmda(char *a)
{
	int		i;
	char	**aux;

	aux = NULL;
	i = 0;
	while (a[i])
	{
		if (a[i] == ' ')
			a[i++] = '_';
		else if (a[i] == '\'')
		{
			a[i] = '_';
			while (a[i] != '\'')
				i++;
			a[i] = '_';
		}
		else
			i++;
	}
	aux = ft_split(a, '_');
	return (aux);
}

char	*make_cmd(char **cmdp, char **cmda)
{
	int		i;
	char	*aux;
	char	*aux2;

	i = 0;
	while (cmdp[i])
	{
		aux = ft_strjoin(cmdp[i], "/");
		aux2 = ft_strjoin(aux, cmda[0]);
		if (access(aux2, 0) == 0)
		{
			free(aux);
			return (aux2);
		}
		i++;
	}
	return (NULL);
}
