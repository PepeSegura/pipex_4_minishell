/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 22:53:49 by psegura-          #+#    #+#             */
/*   Updated: 2023/04/03 15:14:55 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(t_cosas *c, int i)
{
	close(c->pipa[RIGHT]);
	if (i > 0)
		dup2(c->prev, STDIN_FILENO);
	if (i < c->argc - 1)
		dup2(c->pipa[LEFT], STDOUT_FILENO);
	ft_exec(c->argv[i], c->env);
}

void	pipex(t_cosas *c)
{
	int		i;
	int		status;
	pid_t	pid;

	i = 1;
	while (i <= c->argc - 1)
	{
		if (pipe(c->pipa) < 0)
			ft_perror("pipe ");
		pid = fork();
		if (pid < 0)
			ft_perror("fork ");
		else if (pid == CHILD)
			child_process(c, i);
		else
		{
			close(c->prev);
			close(c->pipa[LEFT]);
			c->prev = c->pipa[RIGHT];
		}
		i++;
	}
	i = 0;
	while (i++ < c->argc - 1)
		waitpid(ANY, &status, 0);
}
