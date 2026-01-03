/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 19:02:59 by migarrid          #+#    #+#             */
/*   Updated: 2026/01/03 00:21:24 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

void	parse_map(t_data *data, char *map_path)
{
	get_map_file(data, &data->map, map_path);
	normalize_map_data(&data->map);
	parse_info(data, &data->map);
	// verificar si es correcto
	ft_print_str_array(data->map.map_file, STDOUT);
	ft_printf_fd(STDOUT, MSG_PARSING);
}
