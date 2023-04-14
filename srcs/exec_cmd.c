/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:51:17 by pepe              #+#    #+#             */
/*   Updated: 2023/04/14 13:51:35 by pepe             ###   ########.fr       */
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