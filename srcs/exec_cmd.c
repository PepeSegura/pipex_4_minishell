/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:51:17 by pepe              #+#    #+#             */
/*   Updated: 2023/04/17 16:23:19 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*check_path(char **env, char *cmd)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (env[i] + 5);
		i++;
	}
	ft_putstr_fd(cmd, 2);
	ft_print_error(": No such file or directory");
	return (0);
}

char	*only_path(char *cmd, char **env)
{
	int		i;
	char	**env_paths;
	char	*path;
	char	*path_cmd;
	char	*env_aux;

	env_aux = check_path(env, cmd);
	env_paths = ft_split(env_aux, ':');
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
	return (EXIT_SUCCESS);
}

void	ft_exec(char *argv, char **env, t_cosas *c)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, SPACE);
	if (!cmd || !cmd[0])
	{
		ft_putstr_fd(argv, 2);
		ft_print_error(": command not found");
	}
	path = cmd[0];
	if (cmd[0][0] != '/'
		&& ft_strncmp(cmd[0], "./", 2) && ft_strncmp(cmd[0], "../", 3))
	{
		path = only_path(cmd[0], env);
		if (!path)
		{
			cmd_not_found(cmd[0], c);
			exit_failure(path, cmd, 0);
		}
	}
	execve(path, cmd, env);
	exit_failure(path, cmd, 1);
}
