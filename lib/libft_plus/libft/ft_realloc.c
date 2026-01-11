/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:29:21 by migarrid          #+#    #+#             */
/*   Updated: 2026/01/11 19:33:53 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

void	*ft_realloc(void *old_ptr, size_t new_size)
{
	void	*new_ptr;
	size_t	old_size;
	size_t	*header;

	if (!old_ptr)
		return (ft_alloc(1, new_size));
	if (new_size == 0)
		return (ft_free((void **)&old_ptr), NULL);
	header = (size_t *)old_ptr - 1;
	old_size = *header;
	if (old_size >= new_size)
		return (old_ptr);
	new_ptr = ft_alloc(1, new_size);
	if (!new_ptr)
		return (NULL);
	ft_memcpy(new_ptr, old_ptr, old_size);
	ft_free((void **)&old_ptr);
	return (new_ptr);
}
