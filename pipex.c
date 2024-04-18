/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:48:58 by jrubio-m          #+#    #+#             */
/*   Updated: 2024/04/18 20:28:00 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(char **a, t_utils u, char **e)
{
	char	**cmda;
	char	*cmd;

	u.infile = open(a[1], O_RDONLY, 0644);
	if (u.infile < 0)
	{
		error(2, "no such file or directory: ", a[1]);
		exit(EXIT_SUCCESS);
	}
	u.path = find_path (e);
	u.cmdp = ft_split (u.path, ':');
	cmda = ft_split (a[2], ' ');
	cmd = make_cmd (u.cmdp, cmda);
	if (!cmd)
	{
		error(2, "command not found: ", cmda[0]);
		exit(EXIT_FAILURE);
	}
	close(u.fd[0]);
	dup2(u.infile, STDIN_FILENO);
	dup2(u.fd[1], STDOUT_FILENO);
	if (execve(cmd, cmda, e) < 0)
		exit(EXIT_FAILURE);
	exit (EXIT_SUCCESS);
}

void	child_two(char **a, t_utils u, char **e)
{
	char	**cmda;
	char	*cmd;

	u.outfile = open(a[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (u.outfile < 0)
	{
		error (1, "Outfile", NULL);
		exit (EXIT_FAILURE);
	}
	u.path = find_path (e);
	u.cmdp = ft_split (u.path, ':');
	cmda = ft_split (a[3], ' ');
	cmd = make_cmd (u.cmdp, cmda);
	if (!cmd)
	{
		error (2, "command not found: ", cmda[0]);
		free (cmd);
		exit (EXIT_FAILURE);
	}
	close (u.fd[1]);
	dup2 (u.fd[0], STDIN_FILENO);
	dup2 (u.outfile, STDOUT_FILENO);
	if (execve (cmd, cmda, e) < 0)
		exit (EXIT_FAILURE);
	exit (EXIT_SUCCESS);
}

int	ft_wifexited(int status)
{
	return (WIFEXITED(status));
}

void	waiting(t_pids pid)
{
	waitpid(pid.one, &pid.sone, 0);
	if (!WIFEXITED(pid.sone) || WEXITSTATUS(pid.sone) != EXIT_SUCCESS)
		exit(EXIT_FAILURE);
	waitpid(pid.two, &pid.stwo, 0);
	if (!WIFEXITED(pid.stwo) || WEXITSTATUS(pid.stwo) != EXIT_SUCCESS)
		exit(EXIT_FAILURE);
}

int	main(int c, char **a, char **e)
{
	t_pids	pid;
	t_utils	u;

	if (c == 5)
	{
		if (pipe(u.fd) < 0)
			error(1, "Pipe", NULL);
		pid.one = fork();
		if (pid.one < 0)
			error(1, "Fork", NULL);
		if (pid.one == 0)
			child(a, u, e);
		pid.two = fork();
		if (pid.two < 0)
			error(1, "Fork", NULL);
		if (pid.two == 0)
			child_two(a, u, e);
		close(u.fd[0]);
		close(u.fd[1]);
		waiting(pid);
		return (0);
	}
	ft_printf("\033[0;31mIvalid number of arguments\n");
	ft_printf("\033[0;31mEx: <./pipex> <file1> <cmd1> <cmd2> <file2>\n");
	return (1);
}
