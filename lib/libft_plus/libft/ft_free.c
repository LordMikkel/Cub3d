/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 22:28:45 by migarrid          #+#    #+#             */
/*   Updated: 2026/01/11 19:34:14 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

void	ft_free(void **ptr)
{
	size_t	size;
	size_t	*header_ptr;

	if (!ptr || !*ptr)
		return ;
	header_ptr = (size_t *)(*ptr) - 1;
	size = *header_ptr;
	ft_memnuke(*ptr, size);
	*header_ptr = 0;
	free(header_ptr);
	*ptr = NULL;
}
