/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 22:28:45 by migarrid          #+#    #+#             */
/*   Updated: 2026/01/17 00:27:10 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

void	ft_free(void **ptr)
{
	size_t	size;
	size_t	*header_ptr;
	int		is_locked;

	if (!ptr || !*ptr)
		return ;
	header_ptr = (size_t *)(*ptr) - 1;
	size = *header_ptr & ~MLOCK_FLAG;
	is_locked = *header_ptr & MLOCK_FLAG;
	ft_memnuke(*ptr, size);
	if (is_locked)
		munlock(header_ptr, size + sizeof(size_t));
	*header_ptr = 0;
	free(header_ptr);
	*ptr = NULL;
}
