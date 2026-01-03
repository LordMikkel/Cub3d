/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize_spaces.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 23:23:57 by migarrid          #+#    #+#             */
/*   Updated: 2026/01/03 00:11:15 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

char	*ft_normalize_spaces(char *str, int space)
{
	size_t	i;

	if (!str || !*str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]))
			str[i] = (unsigned char)space;
		i++;
	}
	return (str);
}
