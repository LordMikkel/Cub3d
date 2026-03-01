/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_double_matrix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 19:40:30 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/02 00:05:34 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

void	ft_free_double_matrix(double ***matrix_ptr, size_t rows)
{
	size_t	i;
	double	**matrix;

	if (!matrix_ptr)
		return ;
	matrix = *matrix_ptr;
	if (!matrix || rows <= 0)
	{
		ft_free((void **)matrix_ptr);
		return ;
	}
	i = 0;
	while (i < rows)
	{
		if (matrix[i])
			ft_free((void **)&matrix[i]);
		i++;
	}
	ft_free((void **)matrix_ptr);
}
