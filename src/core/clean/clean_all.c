/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 00:57:59 by migarrid          #+#    #+#             */
/*   Updated: 2026/01/25 06:05:16 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

void	clean_all(t_data *data)
{
	clean_mlx(data);
	clean_enemies(data, &data->map);
	clean_map(data, &data->map);
}
