#include "pipex.h"

char *cmdacc(char *cmda, pip_t pipex)
{
	char	*aux;
	char	*aux2;
	
	while (*pipex.cmdp)
	{
		aux = ft_strjoin(*pipex.cmdp, "/");
		aux2 = ft_strjoin(aux, cmda);
		if (access(aux2, 0) == 0)
		{
			free(aux);
			return(aux2);
		}
		free(aux);
		free(aux2);
		pipex.cmdp++;
	}
	return (NULL);
}
int	err(int e, char *f)
{
	if (e == 1)
	{
		ft_printf("zsh: command not found: %s\n", f);
		return (1);
	}
	if (e == 2)
	{
		ft_printf("zsh: %s: %s\n", strerror(errno), f);
		return (1);
	}
	if (e == 3)
	{
		ft_printf("Invalid Args, Ex: './pipex' 'infile' 'cmd1' 'cmd2' 'outfile'\n");
		return (1);
	}
	if (e == 4)
	{
		ft_printf("%s : Error\n");
		return (1);
	}
	return (0);
}
