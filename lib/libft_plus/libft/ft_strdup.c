/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:38:05 by migarrid          #+#    #+#             */
/*   Updated: 2026/01/11 22:32:01 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*new_str;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	new_str = ft_alloc(len + 1, sizeof(char));
	if (!new_str)
		return (NULL);
	ft_memcpy(new_str, s, len + 1);
	return (new_str);
}
