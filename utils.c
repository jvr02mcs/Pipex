/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:49:43 by jrubio-m          #+#    #+#             */
/*   Updated: 2024/04/18 20:28:39 by jrubio-m         ###   ########.fr       */
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
	if (f == 1)
		write(STDERR_FILENO, "\033[0;31merror:\033[0m ", 19);
	write(STDERR_FILENO, "pipex: ", 8);
	if (f == 1)
		write(STDERR_FILENO, err, ft_strlen(err));
	else
	{
		write(STDERR_FILENO, err, ft_strlen(err));
		if (i)
			write(STDERR_FILENO, i, ft_strlen(i));
	}
	write(STDERR_FILENO, "\n", 2);
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
