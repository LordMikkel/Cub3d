/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memnuke.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:53:39 by migarrid          #+#    #+#             */
/*   Updated: 2026/01/17 01:08:13 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

void	ft_memnuke(void *ptr, size_t size)
{
	volatile unsigned char	*p_byte;
	volatile size_t			*p_chunk;

	if (!ptr)
		return ;
	p_chunk = (volatile size_t *)ptr;
	while (size >= sizeof(size_t))
	{
		*p_chunk = 0;
		p_chunk++;
		size -= sizeof(size_t);
	}
	p_byte = (volatile unsigned char *)p_chunk;
	while (size > 0)
	{
		*p_byte = 0;
		p_byte++;
		size--;
	}
}
