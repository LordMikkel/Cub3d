/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: king <king@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 22:33:18 by migarrid          #+#    #+#             */
/*   Updated: 2025/12/21 00:00:40 by king             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

size_t	ft_count_char(const char *str, int c)
{
	size_t	i;
	size_t	counter;

	if (!str)
		return (0);
	i = 0;
	counter = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			counter++;
		i++;
	}
	return (counter);
}
