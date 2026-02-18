/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbg_print_player_info->c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student->42->fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 20:33:13 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/18 20:34:18 by migarrid         ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

void	dbg_print_player_info(t_plyr *player, int *mouse, int fd)
{
	ft_printf_fd(fd, "Mouse: %d, %d | Dir: %f, %f | Fov: %f, %f | Pos: %f, %f\n",
		mouse[X], mouse[Y],
		player->dir[X], player->dir[Y],
		player->fov[X], player->fov[Y],
		player->pos[X], player->pos[Y]);
}
