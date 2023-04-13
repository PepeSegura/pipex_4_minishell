/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 21:32:40 by psegura-          #+#    #+#             */
/*   Updated: 2023/04/14 00:05:03 by psegura-         ###   ########.fr       */
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
}

int	main(int argc, char **argv, char **env)
{
	t_cosas	c;
	int		i;
	int		status;

	i = 0;
	ft_init_data(&c, argc, argv, env);
	check_path(c.env);
	child_input(&c);
	child_middle(&c);
	child_output(&c, argc - 2);
	close(c.pipa[LEFT]);
	close(c.pipa[RIGHT]);
	while (i++ < argc - 3)
		waitpid(-1, &status, 0);
	return (0);
}
