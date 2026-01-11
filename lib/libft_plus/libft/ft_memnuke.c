/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memnuke.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:53:39 by migarrid          #+#    #+#             */
/*   Updated: 2026/01/11 17:09:40 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

void	ft_memnuke(void *ptr, size_t size)
{
	volatile unsigned char	*ptr_volatile;

	if (!ptr)
		return ;
	ptr_volatile = (volatile unsigned char *)ptr;
	while(size > 0)
	{
		*ptr_volatile = 0;
		ptr_volatile++;
		size--;
	}
}
