/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_str_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 00:11:06 by migarrid          #+#    #+#             */
/*   Updated: 2026/01/11 22:29:25 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

void	ft_free_str_array(char ***array_ptr)
{
	size_t	i;
	char	**array;

	if (!array_ptr || !*array_ptr)
		return ;
	array = *array_ptr;
	i = 0;
	while (array[i])
	{
		ft_free((void **)&array[i]);
		i++;
	}
	ft_free((void **)array_ptr);
}
