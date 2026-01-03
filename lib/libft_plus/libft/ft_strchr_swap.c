/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 23:14:39 by migarrid          #+#    #+#             */
/*   Updated: 2026/01/02 23:29:00 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

char	*ft_strchr_swap(char *str, int old_c, int new_c)
{
	size_t	i;

	if (!str || !*str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char)old_c)
			str[i] = (unsigned char)new_c;
		i++;
	}
	return (str);
}
