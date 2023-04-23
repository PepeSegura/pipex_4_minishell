/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:45:32 by psegura-          #+#    #+#             */
/*   Updated: 2023/04/20 14:03:48 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

pid_t	create_fork(t_cosas *c)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		ft_perror("fork ");
	c->last_pid = pid;
	return (pid);
}

void	create_pipe(t_cosas *c)
{
	if (pipe(c->pipa) < 0)
		ft_perror("pipe ");
}

int	open_files(int identifier, int pos, t_cosas *c)
{
	int	fd;
	int	pipa[2];

	if (identifier == INPUT)
		fd = open(c->argv[pos], O_RDONLY);
	if (identifier == TRUNC)
		fd = open(c->argv[pos], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (identifier == APPEND)
		fd = open(c->argv[pos], O_WRONLY | O_CREAT | O_APPEND, 0666);
	if (identifier == H_DOC)
	{
		if (pipe(pipa) < 0)
			ft_perror("pipe ");
		here_doc(c, pipa[LEFT]);
		close(pipa[LEFT]);
		return (pipa[RIGHT]);
	}
	if (fd < 0 || !identifier)
		ft_perror(c->argv[pos]);
	return (fd);
}

void	wait_child(t_cosas *c)
{
	int	status;
	int	pid;

	while (1)
	{
		pid = waitpid(-1, &status, 0);
		if (pid <= 0)
			break ;
		if (pid == c->last_pid)
		{
			if (WEXITSTATUS(status))
				c->status = WEXITSTATUS(status);
		}
	}		
	exit(c->status);
}
