/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbg_print_map_grid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 02:21:21 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/06 02:22:46 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

void	dbg_print_map_grid(t_map *map, int fd)
{
	ft_print_str_array(map->map_grid, fd);
}
