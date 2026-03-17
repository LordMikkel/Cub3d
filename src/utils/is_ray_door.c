/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ray_door.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:05:24 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/16 23:31:27 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

bool	is_ray_door(t_door *door, t_ray *ray)
{
	if ((int)door->pos[X] == ray->pos[X] && (int)door->pos[Y] == ray->pos[Y])
		return (TRUE);
	return (FALSE);
}
