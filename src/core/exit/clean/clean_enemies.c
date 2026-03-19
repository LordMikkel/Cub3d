/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_enemies.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 06:02:56 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/18 22:48:14 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

void	clean_enemies(t_data *data, t_map *map, t_opt *vars)
{
	(void)map;
	(void)vars;
	if (!data || !map)
		return ;
	if (data->enemies)
		ft_free((void **)&data->enemies);
}
