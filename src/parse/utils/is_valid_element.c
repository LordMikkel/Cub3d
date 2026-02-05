/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_element.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 23:54:46 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/05 02:10:36 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

/**
 * Validates map characters against the allowed whitelist.
 * Ensures the map only contains walls, empty spaces, actors, lights or doors.
 *
 * @param c  The character to validate.
 * @return   TRUE if the character is allowed in the grid.
 */
bool	is_valid_element(char c)
{
	if (c != '1' && c != '0'
		&& c != 'N' && c != 'S'
		&& c != 'E' && c != 'W'
		&& c != ' ' && c != 'X'
		&& c != 'Y' && c != 'Z'
		&& c != 'D' && c != 'L')
		return (FALSE);
	return (TRUE);
}
