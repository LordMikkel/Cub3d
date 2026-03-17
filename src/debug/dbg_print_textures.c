/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbg_print_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 05:40:23 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/17 00:15:08 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

/**
 * Prints the loaded texture configuration.
 * This helper allows us to verify that the parser correctly extracted and
 * stored the data from the file before the game starts.
 *
 * @param map  The map struct containing the texture data.
 * @param fd   The file descriptor to write.
 */
void	dbg_print_texture(t_map *map, int fd)
{
	int	i;

	i = 1;
	while (i < TOTAL_TEXTURE)
	{
		if (i == NORTH)
			ft_putstr_fd("NO ", fd);
		else if (i == EAST)
			ft_putstr_fd("EA ", fd);
		else if (i == SOUTH)
			ft_putstr_fd("SO ", fd);
		else if (i == WEST)
			ft_putstr_fd("WE ", fd);
		else if (i == DOOR)
			ft_putstr_fd("D ", fd);
		else if (i == FLOOR)
			ft_putstr_fd("F ", fd);
		else if (i == CEILING)
			ft_putstr_fd("C ", fd);
		ft_putstr_fd(map->textures[i].path, fd);
		ft_putstr_fd("\n", fd);
		i++;
	}
}
