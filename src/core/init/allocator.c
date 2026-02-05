/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 18:22:21 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/05 00:30:05 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

/**
 * Safe memory allocation wrapper.
 * It enforces a "succeed or die" policy: if allocation fails, the program
 * exits immediately with an error. This simplifies the rest of the codebase,
 * allowing the caller to assume the returned pointer is always valid.
 *
 * @param data   The main struct for error handling.
 * @param nmemb  Number of elements.
 * @param size   Size of each element.
 * @return       A valid pointer to the allocated memory.
 */
void	*allocator(t_data *data, size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = ft_alloc(nmemb, size);
	if (!ptr)
		exit_error(data, ERR_MALLOC, EXIT_FAILURE);
	return (ptr);
}
