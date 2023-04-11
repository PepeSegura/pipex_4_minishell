/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:49:54 by psegura-          #+#    #+#             */
/*   Updated: 2023/04/11 21:29:10 by psegura-         ###   ########.fr       */
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

# ifndef BONUS
#  define BONUS 0
# endif

typedef struct s_cosas {
	int		pipa[2];
	int		prev;
	int		argc;
	char	**argv;
	char	**env;
}	t_cosas;

/* pipex.c */
void	pipex(t_cosas *c);

/* errors.c */
void	ft_perror(char *str);
void	ft_print_error(char *str);

/* utils.c */
void	ft_exec(char *argv, char **env);
int		check_path(char **env);
void	ft_init_data(t_cosas *c, int argc, char **argv, char **env);

/* childs.c */
void	child_input(t_cosas *c);
void	child_middle(t_cosas *c, int i);
void	child_output(t_cosas *c, int i);
#endif
