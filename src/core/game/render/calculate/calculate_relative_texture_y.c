/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_relative_texture_y.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:12:09 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/19 21:09:16 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../inc/cube.h"

void	calculate_relative_texture_y(t_data *data, t_ray *ray, t_txtr *texture)
{
	double	screen_center_y;
	double	theoretical_wall_top_y;
	double	clipped_screen_pixels;
	double	head_offset;

	if (ray->texture->format != TEXTURE)
		return ;
	head_offset = data->player.head[TILT] + data->player.head[BOUNCE];
	ray->tex_step = (double)texture->img->height / ray->line_height;
	screen_center_y = ((double)data->img->height / 2.0) + head_offset;
	theoretical_wall_top_y = screen_center_y - (ray->line_height / 2.0);
	clipped_screen_pixels = ray->draw_start - theoretical_wall_top_y;
	ray->tex[Y] = clipped_screen_pixels * ray->tex_step;
}
