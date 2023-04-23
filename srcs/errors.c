/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 03:33:33 by psegura-          #+#    #+#             */
/*   Updated: 2023/04/20 13:57:22 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_perror(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	ft_print_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	cmd_not_found(char *cmd)
{
	char	*error;

	error = ft_strjoin(cmd, ": command not found\n");
	ft_putstr_fd(error, 2);
	free(error);
}

void	exit_failure(char *err_msg, char **to_free, int flag)
{
	if (flag == 1)
		perror(err_msg);
	ft_free_matrix(to_free);
	exit(flag);
}
