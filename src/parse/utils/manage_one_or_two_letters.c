/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_one_or_two_letters.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 20:30:40 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/19 21:06:40 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

/**
 * Returns the character offset to skip the identifier prefix.
 * Single-letter identifiers (F, C, D) return 1.
 * Two-letter identifiers (NO, SO, WE, EA) return 2.
 *
 * @param type  The identifier type.
 * @return      The offset (1 or 2).
 */
int	manage_one_or_two_letters(int type)
{
	if (type == FLOOR || type == CEILING || type == DOOR)
		return (1);
	return (2);
}
