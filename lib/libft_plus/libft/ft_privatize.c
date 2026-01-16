/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_privatize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 00:11:38 by migarrid          #+#    #+#             */
/*   Updated: 2026/01/17 00:28:49 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

void	*ft_privatize(void *dirty_ptr, size_t size)
{
	void	*secure_copy;

	if (!dirty_ptr)
		return (NULL);
	secure_copy = ft_priv_alloc(1, size);
	if (!secure_copy)
		return (NULL);
	ft_memcpy(secure_copy, dirty_ptr, size);
	ft_free((void **)&dirty_ptr);
	return (secure_copy);
}
