/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfilter_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:05:03 by migarrid          #+#    #+#             */
/*   Updated: 2026/01/11 19:08:49 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

char	*ft_strfilter_c(const char *old_str, int c)
{
	size_t	i;
	size_t	j;
	size_t	new_len;
	char	*new_str;

	if (!old_str)
		return (NULL);
	i = 0;
	new_len = 0;
	while (old_str[i])
		if (old_str[i++] != (unsigned char)c)
			new_len++;
	new_str = ft_alloc(new_len + 1, sizeof (char));
	if (!new_str)
		return (NULL);
	i = 0;
	j = 0;
	while (old_str[i])
	{
		if (old_str[i] != (unsigned char)c)
			new_str[j++] = old_str[i];
		i++;
	}
	new_str[j] = '\0';
	return (new_str);
}
