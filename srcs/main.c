/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 21:32:40 by psegura-          #+#    #+#             */
/*   Updated: 2023/04/15 17:26:40 by psegura-         ###   ########.fr       */
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
		c->limit = argv[2];
		c->flag = H_DOC;
		c->pos = 3;
		if (argc < 6)
			ft_print_error("Not enough arguments!");
	}
}

int	main(int argc, char **argv, char **env)
{
	t_cosas	c;
	int		i;
	int		status;

	if (argc < 5)
		ft_print_error("Not enough arguments!");
	i = 0;
	ft_init_data(&c, argc, argv, env);
	check_path(c.env);
	child_input(&c, c.pos);
	child_middle(&c, c.pos + 1);
	child_output(&c, argc - 2);
	close(c.pipa[LEFT]);
	close(c.pipa[RIGHT]);
	while (i++ < argc - 3)
		waitpid(-1, &status, 0);
	if (c.flag == H_DOC)
		unlink(".here_doc");
	return (0);
}
