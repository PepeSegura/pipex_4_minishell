/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:49:54 by psegura-          #+#    #+#             */
/*   Updated: 2023/04/15 17:20:53 by psegura-         ###   ########.fr       */
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
}	t_cosas;

/* pipex.c */
void	pipex(t_cosas *c);

/* here_doc.c */
void	here_doc(t_cosas *c, int fd);

/* errors.c */
void	ft_perror(char *str);
void	ft_print_error(char *str);

/* utils.c */
pid_t	create_fork(void);
void	create_pipe(t_cosas *c);
int		open_files(int identifier, int pos, t_cosas *c);

/* childs.c */
void	child_input(t_cosas *c, int i);
void	child_middle(t_cosas *c, int i);
void	child_output(t_cosas *c, int i);

/* exec_cmd.c */
void	ft_exec(char *argv, char **env);
int		check_path(char **env);
#endif
