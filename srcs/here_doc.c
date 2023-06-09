/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:36:39 by psegura-          #+#    #+#             */
/*   Updated: 2023/04/16 00:32:52 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	here_doc(t_cosas *c, int fd)
{
	char	*line;
	char	*clean;

	line = "";
	while (1)
	{
		ft_putstr_fd(PROMPT, 1);
		line = get_next_line(STDIN_FILENO);
		if (!line)
			ft_print_error("Malloc KO");
		clean = ft_strtrim(line, "\n");
		if (ft_strcmp(clean, c->limit) != 0)
			ft_putstr_fd(line, fd);
		free(line);
		if (ft_strcmp(clean, c->limit) == 0)
		{
			free(clean);
			break ;
		}
		free(clean);
	}
}
