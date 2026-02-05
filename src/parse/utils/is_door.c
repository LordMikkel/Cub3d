/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_door.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 23:54:14 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/05 02:09:02 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

/**
 * Checks if the character represents a door.
 *
 * @param c  The character to check.
 * @return   TRUE if it is a door ('D').
 */
bool	is_door(char c)
{
	if (c == 'D')
		return (TRUE);
	return (FALSE);
}
