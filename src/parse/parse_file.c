/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 19:02:59 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/04 22:13:23 by migarrid         ###   ########.fr       */
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
	//dbg
	dbg_print_texture(&data->map, STDOUT);
	ft_print_str_array(data->map.map_grid, STDOUT);
	//bdg
	ft_printf_fd(STDOUT, MSG_PARSING);
}
