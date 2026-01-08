/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strleftrim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 23:50:56 by migarrid          #+#    #+#             */
/*   Updated: 2026/01/08 01:34:24 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

char	*ft_strleftrim(const char *str, const char *set)
{
	char	*trimmed;
	size_t	i;

	if (!str || !set)
		return (NULL);
	i = 0;
	while (str[i] && ft_strchr(set, str[i]))
		i++;
	trimmed = ft_strdup(&str[i]);
	if (!trimmed)
		return (NULL);
	return (trimmed);
}
