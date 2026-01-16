/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 17:29:26 by migarrid          #+#    #+#             */
/*   Updated: 2026/01/16 16:57:08 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

void	*ft_alloc(size_t nmemb, size_t size)
{
	void	*user_ptr;
	size_t	*header_ptr;
	size_t	total_user_size;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	total_user_size = nmemb * size;
	header_ptr = ft_calloc(1, total_user_size + sizeof(size_t));
	if (!header_ptr)
		return (NULL);
	*header_ptr = total_user_size;
	user_ptr = (void *)(header_ptr + 1);
	return (user_ptr);
}
