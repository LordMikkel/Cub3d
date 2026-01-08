/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strightrim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 01:31:10 by migarrid          #+#    #+#             */
/*   Updated: 2026/01/08 01:34:35 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

char	*ft_strightrim(const char *str, const char *set)
{
	char	*trimmed;
	size_t	len;

	if (!str || !set)
		return (NULL);
	len = ft_strlen(str);
	while (len > 0 && ft_strchr(set, str[len - 1]))
		len--;
	trimmed = ft_strndup(str, len);
	if (!trimmed)
		return (NULL);
	return (trimmed);
}
