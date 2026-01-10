/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbg_print_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 05:40:23 by migarrid          #+#    #+#             */
/*   Updated: 2026/01/09 05:50:06 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

void	dbg_print_texture(t_map *map, int fd)
{
	int	i;

	i = 1;
	while (i < 7)
	{
		if (i == NORTH)
			ft_putstr_fd("NO ", fd);
		else if (i == EAST)
			ft_putstr_fd("EA ", fd);
		else if (i == SOUTH)
			ft_putstr_fd("SO ", fd);
		else if (i == WEST)
			ft_putstr_fd("WE ", fd);
		else if (i == FLOOR)
			ft_putstr_fd("F ", fd);
		else if (i == CEALING)
			ft_putstr_fd("C ", fd);
		ft_putstr_fd(map->textures[i].path, fd);
		ft_putstr_fd("\n", fd);
		i++;
	}
}
