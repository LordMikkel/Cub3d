/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_color_or_texture.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 20:13:43 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/25 02:39:12 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

/**
 * Dispatches to get_color or get_texture based on line content.
 * If the line contains a comma, it is treated as an RGB color definition.
 * Otherwise, it is treated as a PNG texture path.
 * This allows any identifier (walls, floor, ceiling, door) to accept
 * either format interchangeably.
 *
 * @param data  The main struct.
 * @param map   The map struct to populate.
 * @param line  The raw config line.
 * @param type  The identifier type.
 */
// void	manage_color_or_texture(t_data *data, t_map *map, char *line, int type)
// {
// 	if (ft_strchr(line, ','))
// 		get_color(data, &map->textures[type], line, type);
// 	else
// 		get_texture(data, &map->textures[type], line, type);
// 	map->n_features++;
// }
