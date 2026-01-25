/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:03:16 by davdiaz-          #+#    #+#             */
/*   Updated: 2026/01/25 06:32:58 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

char	*ft_strndup(const char *str, size_t n)
{
	size_t	i;
	size_t	size;
	char	*new_str;

	if (!str)
		return (NULL);
	size = 0;
	while (str[size] && size < n)
		size++;
	new_str = ft_alloc(n + 1, sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < n && str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
