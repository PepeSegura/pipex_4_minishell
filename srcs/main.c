/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 21:32:40 by psegura-          #+#    #+#             */
/*   Updated: 2023/04/20 13:47:15 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_init_data(t_cosas *c, int argc, char **argv, char **env)
{
	ft_memset(c, 0, sizeof(t_cosas));
	c->argc = argc;
	c->argv = argv;
	c->env = env;
	c->prev = STDIN_FILENO;
	c->flag = INPUT;
	c->pos = 2;
	if (ft_strcmp(argv[1], "here_doc") == 0)
	{
		if (argc < 6)
			ft_print_error("Not enough arguments!");
		c->limit = argv[2];
		c->flag = H_DOC;
		c->pos = 3;
		c->fd_h_doc = open_files(H_DOC, 1, c);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_cosas	c;

	if (argc < 5)
		ft_print_error("Not enough arguments!");
	ft_init_data(&c, argc, argv, env);
	child_input(&c, c.pos);
	child_middle(&c, c.pos + 1);
	child_output(&c, argc - 2);
	close(c.pipa[LEFT]);
	close(c.pipa[RIGHT]);
	wait_child(&c);
	return (c.status);
}
