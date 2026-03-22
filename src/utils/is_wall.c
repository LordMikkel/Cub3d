/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:14:41 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/22 17:38:22 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

/**
 * Determines if a specific map character represents a solid, impassable wall.
 * In this engine, both standard '1' blocks and empty spaces (' ') are treated
 * as solid boundaries that rays and entities cannot pass through.
 *
 * @param c  The character from the map grid array.
 * @return   TRUE if the character is a wall or space, FALSE otherwise.
 */
bool	is_wall(char c)
{
	if (c == '1' || c == ' ')
		return (TRUE);
	return (FALSE);
}
