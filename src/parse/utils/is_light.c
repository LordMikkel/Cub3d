/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_light.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 02:10:50 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/22 23:26:51 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

/**
 * Checks if the character represents a light.
 *
 * @param c  The character to check.
 * @return   TRUE if it is a light ('L').
 */
bool	is_light(char c)
{
	if (c == 'L')
		return (TRUE);
	return (FALSE);
}
