/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:49:54 by psegura-          #+#    #+#             */
/*   Updated: 2023/04/16 01:08:39 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

//Header files
# include "pipex.h"
# include "libs.h"

//Libft
# include "../libft/inc/libft.h"

//Constantes
# define SPACE	' '
# define ANY	-1
# define CHILD	0

# define TRUE	1
# define FALSE	0
# define LEFT	1
# define RIGHT	0

# define INPUT	1
# define TRUNC 	2
# define APPEND	3
# define H_DOC	4

# define PROMPT	"\033[0;32m➜  \033[0;36mHere_doc \033[1;33m✗ \033[0m"

typedef struct s_cosas {
	int		pipa[2];
	int		prev;
	int		argc;
	char	**argv;
	char	**env;
	char	*limit;
	int		flag;
	int		pos;
	int		last_cmd;
	int		exit_code;
}	t_cosas;

/* pipex.c */
void	pipex(t_cosas *c);

/* here_doc.c */
void	here_doc(t_cosas *c, int fd);

/* errors.c */
void	ft_perror(char *str);
void	ft_print_error(char *str);
void	cmd_not_found(char *cmd, t_cosas *c);
void	exit_failure(char *err_msg, char **to_free, int flag);

/* utils.c */
pid_t	create_fork(void);
void	create_pipe(t_cosas *c);
int		open_files(int identifier, int pos, t_cosas *c);

/* childs.c */
void	child_input(t_cosas *c, int i);
void	child_middle(t_cosas *c, int i);
void	child_output(t_cosas *c, int i);

/* exec_cmd.c */
void	ft_exec(char *argv, char **env, t_cosas *c);
char	*check_path(char **env, char *cmd);
#endif
