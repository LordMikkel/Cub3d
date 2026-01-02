/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 19:02:59 by migarrid          #+#    #+#             */
/*   Updated: 2026/01/02 04:44:29 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

void	parse_map(t_data *data, char *map_path)
{
	get_map_file(data, &data->map, map_path);
	// Quitar saltos de linea
	// parsear de verdad el mapa extrayendo cada parte
	// verificar si es correcto
	ft_printf_fd(STDOUT, MSG_PARSING);
}
