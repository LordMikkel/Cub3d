/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_jump.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 21:49:28 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/08 21:50:40 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

void	init_jump(t_plyr *player)
{
	player->jumping = TRUE;
	player->jump_vel = JUMP_FORCE;
}
