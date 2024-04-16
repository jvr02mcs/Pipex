#include "pipex.h"

void write_a(char **a)
{
	int i;

	i = 0;
	while (*a)
	{
		printf("%s : %d\n", *a, i);
		i++;
		a++;
	}
}
char	*make_cmd(char **cmdp, char **cmda)
{
	int i;
	char *aux;
	char *aux2;

	i = 0;
	if (access(cmda[0], 0) == 0)
		return (cmda[0]);
	while(cmdp[i])
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
char	*find_path(char **e)
{
	while (*e)
	{
		if (ft_strncmp(*e, "PATH=", 5) == 0)
			return (*e + 5);
		e++;
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

void	childd(char **a, char **cmdp, int fd[2], char **e)
{
	int		infile;
	char	**cmda;
	char	*cmd;
	infile = open(a[1], O_RDONLY, 0644);
	if (infile < 0)
		error(2, "No such file or directory: ", a[1]);
	cmda = ft_split(a[2], ' ');
	cmd = make_cmd(cmdp, cmda);
	if (!cmd)
	{
		error(2, "Command not found: ", a[2]);
		exit(EXIT_FAILURE);
	}
	close(fd[0]);
	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	if (execve(cmd, cmda, e) < 0)
		exit(EXIT_FAILURE);
	exit (EXIT_SUCCESS);
}
int	daddy(char **a, char **cmdp, int fd[2], char **e)
{
	int		outfile;
	char	**cmda;
	char	*cmd;
	outfile = open(a[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (outfile < 0)
		error(2, "Outfile error: ", NULL);
	cmda = ft_split(a[3], ' ');
	cmd = make_cmd(cmdp, cmda);
	if (!cmd)
	{
		error(2, "Command not found: ", a[3]);
		exit(EXIT_FAILURE);
	}
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	if (execve(cmd, cmda, e) < 0)
		exit(EXIT_FAILURE);
	exit (EXIT_SUCCESS);
}

int main (int c, char **a, char **e)
{
	int		fd[2];
	char	*path;
	char	**cmdp;
	pid_t	pid;
	if (c == 5)
	{
		path = find_path(e);
		cmdp = ft_split(path, ':');
		if (pipe(fd) < 0)
			error(1, "Pipe", NULL);
		pid = fork();
		if (pid < 0)
			error(1, "Fork", NULL);
		if (pid == 0)
			childd(a, cmdp, fd, e);
		waitpid(pid, NULL, 0);
		daddy(a, cmdp, fd, e);
	return (0);
	}
	return (1);
}
