/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_opt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 19:40:02 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/08 01:34:14 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

void	init_opt(t_data *data)
{
	init_cores(data, &data->vars);
	data->vars.half_img_height = data->img->height / 2;
	data->vars.half_img_width = data->img->width / 2;
	data->vars.initial_min_dist_sq = DOOR_INTERACT_DIST * DOOR_INTERACT_DIST;
	data->vars.gun_pos[X] = (data->img->width - GUN_TXTR_WIDTH_FHD) / 2;
	data->vars.gun_pos[Y] = data->img->height - GUN_TXTR_HEIGH_FHD;
}
