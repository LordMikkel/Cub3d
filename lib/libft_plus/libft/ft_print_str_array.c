/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 03:47:52 by migarrid          #+#    #+#             */
/*   Updated: 2026/01/02 03:55:04 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

void	ft_print_str_array(char **array, int fd)
{
	size_t	i;

	if (!array || !*array)
		return ;
	i = 0;
	while (array[i])
	{
		ft_putstr_fd(array[i], fd);
		ft_putchar_fd('\n', fd);
		i++;
	}
}
