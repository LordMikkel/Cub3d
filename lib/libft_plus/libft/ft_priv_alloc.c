/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_priv_alloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 00:35:04 by migarrid          #+#    #+#             */
/*   Updated: 2026/01/17 00:38:18 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

void	*ft_priv_alloc(size_t nmemb, size_t size)
{
	void	*user_ptr;
	size_t	*header_ptr;
	size_t	total_user_size;

	if (size != 0 && nmemb > (MAX_ALLOC_SIZE - sizeof(size_t)) / size)
		return (NULL);
	total_user_size = nmemb * size;
	header_ptr = ft_calloc(1, total_user_size + sizeof(size_t));
	if (!header_ptr)
		return (NULL);
	*header_ptr = total_user_size | MLOCK_FLAG;
	if (mlock(header_ptr, total_user_size + sizeof(size_t)) != 0)
		return (free(header_ptr), NULL);
	user_ptr = (void *)(header_ptr + 1);
	return (user_ptr);
}
