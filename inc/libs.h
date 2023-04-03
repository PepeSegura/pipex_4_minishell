/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:52:05 by psegura-          #+#    #+#             */
/*   Updated: 2022/11/19 15:01:09 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBS_H
# define LIBS_H

//Close, Write, Access, Dup, Dup2, Execve, Fork, Pipe, Unlink
# include <unistd.h>

//Read, Perror, Strerror
# include <stdio.h>

//Malloc, Free, Exit
# include <stdlib.h>

//Open
# include <fcntl.h>

//Wait, Waitpid
# include <sys/wait.h>

#endif