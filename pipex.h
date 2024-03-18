#ifndef PIPEX_H
# define PIPEX_H

typedef struct
{
	char *c1;
	char *c2;
	char *path;
	char **cmdp;
	char **cmda1;
	char **cmda2;
	int infile;
	int outfile;
	int fd[2];

} pip_t ;

# include <stdlib.h>
# include <errno.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "Libft/libft.h"
#define IN 0
#define OUT 1
int	err(int e, char *f);
char *cmdacc(char *cmda, pip_t pipex);

#endif