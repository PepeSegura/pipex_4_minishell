/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:45:32 by psegura-          #+#    #+#             */
/*   Updated: 2023/04/14 13:52:07 by pepe             ###   ########.fr       */
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
	if (fd < 0 || !identifier)
		ft_perror(c->argv[pos]);
	return (fd);
}
