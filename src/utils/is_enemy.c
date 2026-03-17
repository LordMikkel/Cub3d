/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 23:53:52 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/16 23:30:55 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

/**
 * Checks if the character represents a enemy.
 *
 * @param c  The character to check.
 * @return   TRUE for any valid enemy code (X, Y, Z).
 */
bool	is_enemy(char c)
{
	if (c == 'X' || c == 'Y' || c == 'Z')
		return (TRUE);
	return (FALSE);
}
