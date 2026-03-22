/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_enemy_in_the_same_cell.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 18:40:39 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/22 18:44:00 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

bool	is_enemy_in_the_same_cell(double dist_sq)
{
	if (dist_sq < 0.5)
		return (TRUE);
	return (FALSE);
}
