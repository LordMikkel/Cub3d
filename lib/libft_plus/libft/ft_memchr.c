/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 22:18:04 by migarrid          #+#    #+#             */
/*   Updated: 2026/01/11 22:30:50 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	unsigned char		uc;

	uc = (unsigned char)c;
	ptr = (const unsigned char *)s;
	while (n > 0)
	{
		if (*ptr == uc)
			return ((void *)ptr);
		ptr++;
		n--;
	}
	return (NULL);
}
