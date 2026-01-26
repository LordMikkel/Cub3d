/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:19:01 by migarrid          #+#    #+#             */
/*   Updated: 2026/01/25 21:17:24 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

char	**ft_arraydup(char **str_array)
{
	size_t	i;
	size_t	len;
	char	**dup;

	if (!str_array)
		return (NULL);
	len = ft_arraylen(str_array);
	dup = ft_alloc(len + 1, sizeof(char *));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = ft_strdup(str_array[i]);
		if(!dup[i])
			return (ft_free_str_array(&dup), NULL);
		i++;
	}
	dup[i] = NULL;
	return (dup);
}
