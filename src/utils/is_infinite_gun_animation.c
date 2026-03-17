/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_infinite_gun_animation.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 23:38:39 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/16 23:39:21 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

bool	is_infinite_gun_animation(t_gun *gun)
{
	if (gun->state == GUN_IDLE_A || gun->state == GUN_AIM)
		return (TRUE);
	return (FALSE);
}
