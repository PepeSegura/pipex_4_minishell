/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:32:24 by psegura-          #+#    #+#             */
/*   Updated: 2023/04/11 21:58:48 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_input(t_cosas *c)
{
	int	fd_in;
	pid_t pid;

	if (pipe(c->pipa) < 0)
		ft_perror("pipe ");
	pid = fork();
	if (pid < 0)
		ft_perror("fork ");
	if (pid == CHILD)
	{
		fd_in = open(c->argv[1], O_RDONLY);
		if (fd_in < 0)
			ft_perror(c->argv[1]);
		dprintf(2, "FIRST:\n");
		dprintf(2, "fd_%s: [%d]\n", c->argv[1], fd_in);
		dprintf(2, "pipe_left: [%d] pipe_right: [%d]\n", c->pipa[LEFT], c->pipa[RIGHT]);
		dprintf(2, "cmd_in: [%s]\n\n", c->argv[2]);

		// close(c->pipa[RIGHT]);
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

void	child_middle(t_cosas *c, int i)
{
	// int		status;
	pid_t	pid;

	i = 3;
	while (i < c->argc - 2)
	{
		if (pipe(c->pipa) < 0)
			ft_perror("pipe ");
		pid = fork();
		if (pid < 0)
			ft_perror("fork ");
		else if (pid == CHILD)
		{
			dprintf(2, "MIDDLE:\n");
			dprintf(2, "prev: [%d]\n", c->prev);
			dprintf(2, "pipe_left: [%d] pipe_right: [%d]\n", c->pipa[LEFT], c->pipa[RIGHT]);
			dprintf(2, "cmd: [%s]\n\n", c->argv[i]);
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
	int	fd_out;
	pid_t pid;

	pid = fork();
	if (pid < 0)
		ft_perror("fork ");
	if (pid == CHILD)
	{
		fd_out = open(c->argv[c->argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if (fd_out == -1)
			ft_perror(c->argv[c->argc - 1]);

		dprintf(2, "LAST:\n");
		dprintf(2, "prev: [%d]\n", c->prev);
		dprintf(2, "pipe_left: [%d] pipe_right: [%d]\n", c->pipa[LEFT], c->pipa[RIGHT]);
		dprintf(2, "fd_%s: [%d]\n", c->argv[c->argc - 1], fd_out);
		dprintf(2, "cmd_out: [%s]\n\n", c->argv[i]);

		close(c->pipa[LEFT]);
		dup2(c->prev, STDIN_FILENO);
		dup2(fd_out, STDOUT_FILENO);
		close(c->prev);
		ft_exec(c->argv[i], c->env);
	}
}
