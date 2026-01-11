/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_int_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 00:22:37 by migarrid          #+#    #+#             */
/*   Updated: 2026/01/11 19:51:01 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

void	ft_free_int_matrix(int ***matrix_ptr, size_t rows)
{
	size_t	i;
	int		**matrix;

	if (!matrix_ptr)
		return ;
	matrix = *matrix_ptr;
	if (!matrix || rows <= 0)
		return (ft_free((void **)matrix_ptr));
	i = 0;
	while (i < rows)
	{
		if (matrix[i])
			ft_free((void **)&matrix[i]);
		i++;
	}
	ft_free((void **)matrix_ptr);
}
