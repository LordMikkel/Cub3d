/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ray_hit_the_door.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 21:29:35 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/05 21:37:41 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

bool	is_ray_hit_the_door(t_door *door, t_ray *ray)
{
	if ((int)door->pos[X] == ray->pos[X] && (int)door->pos[Y] == ray->pos[Y])
		return (TRUE);
	return (FALSE);
}
