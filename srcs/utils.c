/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:45:32 by psegura-          #+#    #+#             */
/*   Updated: 2023/04/11 17:46:22 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (i);
		i++;
	}
	ft_print_error("There is no PATH defined in the enviroment\n");
	return (i);
}

static char	*only_path(char *cmd, char **env)
{
	int		i;
	char	**env_paths;
	char	*path;
	char	*path_cmd;

	i = check_path(env);
	env_paths = ft_split(env[i] + 5, ':');
	i = 0;
	while (env_paths[i])
	{
		path = ft_strjoin(env_paths[i], "/");
		path_cmd = ft_strjoin(path, cmd);
		free(path);
		if (access(path_cmd, X_OK) == 0)
		{
			ft_free_matrix(env_paths);
			return (path_cmd);
		}
		free(path_cmd);
		i++;
	}
	ft_free_matrix(env_paths);
	ft_putstr_fd(cmd, 2);
	ft_print_error(": command not found\n");
	return (EXIT_SUCCESS);
}

void	ft_exec(char *argv, char **env)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, SPACE);
	if (!cmd || !cmd[0])
		ft_print_error("command not found\n");
	path = only_path(cmd[0], env);
	if (execve(path, cmd, env) == -1)
		ft_perror("exec");
}

void	ft_init_data(t_cosas *c, int argc, char **argv, char **env)
{
	ft_memset(c, 0, sizeof(t_cosas));
	c->argc = argc;
	c->argv = argv;
	c->env = env;
	c->prev = STDIN_FILENO;
}
