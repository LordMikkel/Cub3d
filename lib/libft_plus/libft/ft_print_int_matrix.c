/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_matrix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 03:51:21 by migarrid          #+#    #+#             */
/*   Updated: 2026/01/03 00:13:41 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

void	ft_print_int_matrix(int **matrix, size_t rows, size_t cols, int fd)
{
	size_t	i;
	size_t	j;

	if (!matrix || rows == 0 || cols == 0)
		return ;
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			ft_putnbr_fd(matrix[i][j], fd);
			if (j < cols - 1)
				ft_putchar_fd(' ', fd);
			j++;
		}
		ft_putchar_fd('\n', fd);
		i++;
	}
}
