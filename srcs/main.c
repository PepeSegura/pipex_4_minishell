/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 21:32:40 by psegura-          #+#    #+#             */
/*   Updated: 2023/04/11 21:51:43 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_cosas	c;

	ft_init_data(&c, argc, argv, env);
	check_path(c.env);
	
	child_input(&c);
	child_middle(&c, 3);
	child_output(&c, argc - 2);
	// pipex(&c);
	return (0);
}
