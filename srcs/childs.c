/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:32:24 by psegura-          #+#    #+#             */
/*   Updated: 2023/04/15 01:36:05 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_input(t_cosas *c)
{
	int		fd_in;
	pid_t	pid;

	create_pipe(c);
	pid = create_fork();
	if (pid == CHILD)
	{
		fd_in = open_files(INPUT, 1, c);
		close(c->pipa[RIGHT]);
		dup2(fd_in, STDIN_FILENO);
		dup2(c->pipa[LEFT], STDOUT_FILENO);
		close(c->pipa[LEFT]);
		close(c->pipa[RIGHT]);
		close(fd_in);
		ft_exec(c->argv[2], c->env);
	}
	else
	{
		close(c->pipa[LEFT]);
		c->prev = c->pipa[RIGHT];
	}
}

void	child_middle(t_cosas *c)
{
	int		i;
	pid_t	pid;

	i = 3;
	while (i < c->argc - 2)
	{
		create_pipe(c);
		pid = create_fork();
		if (pid == CHILD)
		{
			close(c->pipa[RIGHT]);
			if (i > 0)
				dup2(c->prev, STDIN_FILENO);
			if (i < c->argc - 2)
				dup2(c->pipa[LEFT], STDOUT_FILENO);
			ft_exec(c->argv[i], c->env);
		}
		else
		{
			close(c->prev);
			close(c->pipa[LEFT]);
			c->prev = c->pipa[RIGHT];
		}
		i++;
	}
}

void	child_output(t_cosas *c, int i)
{
	int		fd_out;
	pid_t	pid;

	pid = create_fork();
	if (pid == CHILD)
	{
		close(c->pipa[LEFT]);
		fd_out = open_files(TRUNC, c->argc - 1, c);
		dup2(c->prev, STDIN_FILENO);
		dup2(fd_out, STDOUT_FILENO);
		close(c->prev);
		close(fd_out);
		ft_exec(c->argv[i], c->env);
	}
}
