/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbg_print_map_grid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 02:21:21 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/19 02:51:36 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

/**
 * Prints the entire map grid to a file descriptor.
 * Iterates through every row of the map and writes it as a string.
 * Useful for verifying the map layout or inspecting the flood fill
 * result during parsing and validation debugging.
 *
 * @param map  The map struct containing the grid to print.
 * @param fd   The file descriptor to write to (e.g. STDOUT or STDERR).
 */
void	dbg_print_map_grid(t_map *map, int fd)
{
	ft_print_str_array(map->map_grid, fd);
}
