/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 00:57:59 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/05 23:07:52 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

/**
 * Frees all program resources.
 * This function groups the cleanup logic by module.
 * Centralizing the shutdown here ensures we track every
 * allocation and prevents memory leaks when the game ends.
 * the game ends. Finally, it zeroes out the main struct
 *
 * @param data  The main struct to be freed.
 */
void	clean_all(t_data *data)
{
	clean_lights(&data->map);
	clean_doors(data, &data->map);
	clean_enemies(data, &data->map);
	clean_map(data, &data->map);
	clean_mlx(data);
	ft_memnuke(data, sizeof(t_data));
}
