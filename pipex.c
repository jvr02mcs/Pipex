#include "pipex.h"

static char	*findpath(char **e)
{
	int	i;

	i = 0;
	while (e[i])
	{
		if (ft_strncmp("PATH=", e[i], 5) == 0)
			return (e[i] + 5);
		i++;
	}
	return (NULL);
}
static void	lilkidd(char **a, char **e , pip_t pipex, int c)
{
	if (((pipex.infile = open(a[1], O_RDONLY, 0777)) < 0))
	{
		err(2, a[1]);
		if (c == 1)
			err(1, pipex.cmda2[0]);
		exit(1);
	}
	pipex.cmda1 = ft_split(a[2], ' ');
	if(!(pipex.c1 = cmdacc(pipex.cmda1[0], pipex)))
	{
		err(1, pipex.cmda1[0]);
		if (c == 1)
			err(1, pipex.cmda2[0]);
		exit(1);
	}
	close(pipex.fd[IN]);
	dup2(pipex.fd[OUT], STDOUT_FILENO);
	dup2(pipex.infile, STDIN_FILENO);
	execve(pipex.c1, pipex.cmda1, e);
}

static void	daddy(char **a, char **e, pip_t pipex)
{
	if ((pipex.outfile = open(a[4], O_CREAT | O_WRONLY | O_TRUNC, 0777)) < 0)
		err(2, a[4]);
	close(pipex.fd[OUT]);
	dup2(pipex.fd[IN], STDIN_FILENO);
	dup2(pipex.outfile, STDOUT_FILENO);
	execve(pipex.c2, pipex.cmda2, e);
}

int	main (int c, char **a, char **e)
{
	int i;
	pid_t pid;
	pip_t pipex;

	i = 0;
	if (c != 5)
		return (err(3, NULL));
	if (pipe(pipex.fd) < 0)
		return (err(4, "Pipe"));
	pipex.cmda2 = ft_split(a[3], ' ');
	pipex.path = findpath(e);
	pipex.cmdp = ft_split(pipex.path, ':');
	if(!(pipex.c2 = cmdacc(pipex.cmda2[0], pipex)))
		i++;
	if ((pid = fork()) < 0)
		return (err(4, "Fork"));
	if (pid == 0)
		lilkidd(a, e, pipex, i);
	waitpid(pid, NULL, 0);
	daddy(a, e, pipex);
	return (0);
}
