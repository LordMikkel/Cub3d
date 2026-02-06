/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 19:02:59 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/06 02:23:32 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

/**
 * Manages the map loading process.
 * It breaks down the parsing into specific stages: reading the file,
 * organizing the data, and finally validating the map with flood fill.
 *
 * @param data      The main struct where map info will be stored.
 * @param map_path  The path to the .cub file to be read.
 */
void	parse_file(t_data *data, char *map_path)
{
	get_file_info(data, &data->map, map_path);
	normalize_info(&data->map);
	parse_info(data, &data->map);
	validate_map(data, &data->map);
	dbg_print_texture(&data->map, STDOUT);
	dbg_print_map_grid(data->map.map_grid, STDOUT);
	ft_printf_fd(STDOUT, MSG_PARSING);
}
