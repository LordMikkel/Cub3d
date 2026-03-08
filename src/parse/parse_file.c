/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 19:02:59 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/08 16:10:20 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

/**
 * Manages the map loading process.
 * It breaks down the parsing into specific stages: reading the file,
 * organizing the data, and finally validating the map with flood fill.
 * debug options:
 * dbg_print_texture(&data->map, STDOUT);
 * dbg_print_map_grid(&data->map, STDOUT);
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
	ft_printf_fd(STDOUT, MSG_PARSING);
}
