#ifndef PIPEX_H
# define PIPEX_H
# include <stdlib.h>
# include <errno.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "ft_printf/ft_printf.h"

typedef struct s_pip
{
	char	*c1;
	char	*c2;
	char	*path;
	char	**cmdp;
	char	**cmda;
	int		infile;
	int		outfile;
	int		fd[2];

}	t_pip;

int	handle_errors(char *error_msg);

#endif
