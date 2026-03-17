/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_door_close.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:48:35 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/16 23:30:51 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

/**
 * Checks if the character represents a close door.
 *
 * @param c  The character to check.
 * @return   TRUE if it is a close door ('D').
 */
bool	is_door_close(char c)
{
	if (c == 'D')
		return (TRUE);
	return (FALSE);
}
