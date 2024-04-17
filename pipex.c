/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:46:20 by jrubio-m          #+#    #+#             */
/*   Updated: 2024/04/17 15:42:34 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	childd(char **a, t_utils u, char *cmd, char **e)
{
	char	**cmda;

	u.infile = open(a[1], O_RDONLY, 0644);
	if (u.infile < 0)
		error(2, "No such file or directory: ", a[1]);
	cmda = ft_make_cmda(a[2]);
	cmd = make_cmd(u.cmdp, cmda);
	if (!cmd)
	{
		if (!(u.infile < 0))
			error(2, "command not found: ", cmda[0]);
		exit(EXIT_FAILURE);
	}
	if (u.infile < 0)
		exit(EXIT_FAILURE);
	close(u.fd[0]);
	dup2(u.infile, STDIN_FILENO);
	dup2(u.fd[1], STDOUT_FILENO);
	if (execve(cmd, cmda, e) < 0)
		exit(127);
	exit (EXIT_SUCCESS);
}

void	daddy(char **a, t_utils u, char *cmd, char **e)
{
	char	**cmda;

	u.outfile = open(a[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (u.outfile < 0)
	{
		error(2, "Outfile error: ", NULL);
		exit(EXIT_FAILURE);
	}
	cmda = ft_make_cmda(a[3]);
	cmd = make_cmd(u.cmdp, cmda);
	if (!cmd)
	{
		error(2, "command not found: ", cmda[0]);
		exit(127);
	}
	close(u.fd[1]);
	dup2(u.fd[0], STDIN_FILENO);
	dup2(u.outfile, STDOUT_FILENO);
	if (execve(cmd, cmda, e) < 0)
		exit(127);
	exit (EXIT_SUCCESS);
}

void	ft_pipex(char **a, char *c1, char *c2, char **e)
{
	pid_t	pid;
	t_utils	u;

	u.path = find_path(e);
	u.cmdp = ft_split(u.path, ':');
	if (pipe(u.fd) < 0)
		error(1, "Pipe", NULL);
	pid = fork();
	if (pid < 0)
		error(1, "Fork", NULL);
	if (pid == 0)
		childd(a, u, c1, e);
	waitpid(pid, NULL, 0);
	daddy(a, u, c2, e);
}

int	main(int c, char **a, char **e)
{
	char	*c1;
	char	*c2;

	c1 = NULL;
	c2 = NULL;
	if (c == 5)
	{
		ft_pipex(a, c1, c2, e);
		return (0);
	}
	ft_printf("Ivalid number of arguments\n");
	ft_printf("Ex: <./pipex> <file1> <cmd1> <cmd2> <file2>\n");
	return (1);
}
