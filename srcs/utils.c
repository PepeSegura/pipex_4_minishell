/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:45:32 by psegura-          #+#    #+#             */
/*   Updated: 2023/04/16 16:47:41 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

pid_t	create_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		ft_perror("fork ");
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

	if (identifier == INPUT)
		fd = open(c->argv[pos], O_RDONLY);
	if (identifier == TRUNC)
		fd = open(c->argv[pos], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (identifier == APPEND)
		fd = open(c->argv[pos], O_WRONLY | O_CREAT | O_APPEND, 0666);
	if (identifier == H_DOC)
	{
		fd = open(".here_doc", O_RDWR | O_CREAT | O_APPEND, 0666);
		here_doc(c, fd);
		close(fd);
		fd = open(".here_doc", O_RDONLY);
	}
	if (fd < 0 || !identifier)
		ft_perror(c->argv[pos]);
	return (fd);
}

void	wait_child(void)
{
	int	status;
	int	pid;

	pid = 42;
	while (1)
		if (pid <= 0)
			break ;
	else
		pid = waitpid(-1, &status, 0);
}
