#include "pipex.h"

typedef struct s_files
{
	int infile;
	int outfile;
	int fd[2];
} t_files;

char	*make_cmd(char **cmdp, char **cmda)
{
	int i;
	char *aux;
	char *aux2;

	i = 0;
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
char **ft_make_cmda(char *a)
{
	int	i;
	char **aux;

	aux = NULL;
	i = 0;
	while (a[i])
	{
		if (a[i] == ' ')
			a[i++] = '_';
		else if (a[i] == '\'')
		{
			a[i] = '_';
			while(a[i] != '\'')
				i++;
			a[i] = '_';
		}
		else
			i++;
	}
	aux = ft_split(a, '_');
	return (aux);
}

void	childd(char **a, char **cmdp, t_files f, char *cmd, char **e)
{
	char	**cmda;
	f.infile = open(a[1], O_RDONLY, 0644);
	if (f.infile < 0)
		error(2, "No such file or directory: ", a[1]);
	cmda = ft_make_cmda(a[2]);
	cmd = make_cmd(cmdp, cmda);
	if (!cmd)
	{
		if (!(f.infile < 0))
			error(2, "command not found: ", cmda[0]);
		exit(EXIT_FAILURE);
	}
	if (f.infile < 0)
		exit(EXIT_FAILURE);
	close(f.fd[0]);
	dup2(f.infile, STDIN_FILENO);
	dup2(f.fd[1], STDOUT_FILENO);
	if (execve(cmd, cmda, e) < 0)
		exit(127);
	exit (EXIT_SUCCESS);
}
void	daddy(char **a, char **cmdp, t_files f, char *cmd, char **e)
{
	char	**cmda;

	f.outfile = open(a[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (f.outfile < 0)
	{
		error(2, "Outfile error: ", NULL);
		exit(EXIT_FAILURE);
	}
	cmda = ft_make_cmda(a[3]);
	cmd = make_cmd(cmdp, cmda);
	if (!cmd)
	{
		error(2, "command not found: ", cmda[0]);
		exit(127);
	}
	close(f.fd[1]);
	dup2(f.fd[0], STDIN_FILENO);
	dup2(f.outfile, STDOUT_FILENO);
	if (execve(cmd, cmda, e) < 0)
		exit(127);
	exit (EXIT_SUCCESS);
}

void	ft_pipex(char **a, char *c1, char *c2, char **e)
{
	char	*path;
	char	**cmdp;
	pid_t	pid;
	t_files f;

	path = find_path(e);
	cmdp = ft_split(path, ':');
	if (pipe(f.fd) < 0)
		error(1, "Pipe", NULL);
	pid = fork();
	if (pid < 0)
		error(1, "Fork", NULL);
	if (pid == 0)
		childd(a, cmdp, f, c1, e);
	waitpid(pid, NULL, 0);
	daddy(a, cmdp, f, c2, e);
}
int main (int c, char **a, char **e)
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
