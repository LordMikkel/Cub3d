/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraylen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 10:35:02 by davdiaz-          #+#    #+#             */
/*   Updated: 2026/01/16 00:20:15 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

size_t	ft_arraylen(char **str_array)
{
	size_t	count;

	if (!str_array)
		return (-1);
	count = 0;
	while (str_array[count] != NULL)
		count++;
	return (count);
}
