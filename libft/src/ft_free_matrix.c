/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:13:50 by psegura-          #+#    #+#             */
/*   Updated: 2022/11/28 18:14:01 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_matrix(char **matrix)
{
	int	i;

	i = -1;
	while (matrix[++i])
		;
	while (--i >= 0)
		free(matrix[i]);
	free(matrix);
}
