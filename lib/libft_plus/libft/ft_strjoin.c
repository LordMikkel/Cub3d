/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:49:43 by migarrid          #+#    #+#             */
/*   Updated: 2026/01/11 22:32:18 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*strjoin;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	strjoin = ft_alloc(len1 + len2 + 1, sizeof(char));
	if (!strjoin)
		return (NULL);
	ft_strlcpy(strjoin, s1, len1 + 1);
	ft_strlcat(strjoin, s2, len1 + len2 + 1);
	return (strjoin);
}
