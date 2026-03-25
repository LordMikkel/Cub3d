/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:30:20 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/25 02:31:41 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

size_t	ft_putendl_fd(char *s, int fd)
{
	size_t	len;

	if (!s)
		return (-1);
	len = 0;
	while (*s)
	{
		if (write(fd, s, 1) == -1)
			return (-1);
		len++;
		s++;
	}
	if (write(fd, "\n", 1) == -1)
		return (-1);
	len++;
	return (len);
}
