/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 18:22:21 by migarrid          #+#    #+#             */
/*   Updated: 2026/01/15 23:38:47 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

void	*allocator(t_data *data, size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = ft_alloc(nmemb, size);
	if (!ptr)
		exit_error(data, ERR_MALLOC, EXIT_FAILURE);
	return (ptr);
}
