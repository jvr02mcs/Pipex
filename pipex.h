/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:09:27 by jrubio-m          #+#    #+#             */
/*   Updated: 2024/04/18 17:14:21 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

typedef struct s_utils
{
	int		infile;
	int		outfile;
	int		fd[2];
	char	*path;
	char	**cmdp;
}	t_utils;

typedef struct s_pids
{
	pid_t	one;
	pid_t	two;
	int		sone;
	int		stwo;

}	t_pids;

char	*find_path(char **e);
void	error(int f, char *err, char *i);
char	*make_cmd(char **cmdp, char **cmda);

#endif
