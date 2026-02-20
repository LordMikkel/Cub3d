/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_relative_texture_y.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:12:09 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/20 00:09:35 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../inc/cube.h"

/**
 * Calculates the vertical texture scaling and its starting coordinate.
 *
 * If the wall is a solid color, this math is skipped. Otherwise, it finds
 * the scaling step: how many image pixels to advance per screen pixel.
 * It then shifts the screen's visual center using the player's head tilt
 * and bounce to simulate looking around or walking. If a wall is very close,
 * its top might extend beyond the upper edge of the monitor. By finding
 * the theoretical top of the wall and subtracting where we actually start
 * drawing, we calculate the clipped screen pixels. Multiplying these missed
 * pixels by the step gives the exact starting Y coordinate on the texture.
 *
 * @param data     Main structure containing screen dimensions and player.
 * @param ray      The ray containing line height and drawing boundaries.
 * @param texture  The texture structure to get the true image height.
 */
void	calculate_relative_texture_y(t_data *data, t_ray *ray, t_txtr *texture)
{
	double	screen_center_y;
	double	theoretical_wall_top_y;
	double	clipped_screen_pixels;

	if (ray->texture->format != TEXTURE)
		return ;
	ray->tex_step = (double)texture->img->height / ray->line_height;
	screen_center_y = (double)data->img->height / 2.0 + data->player.head[POS];
	theoretical_wall_top_y = screen_center_y - (ray->line_height / 2.0);
	clipped_screen_pixels = ray->draw_start - theoretical_wall_top_y;
	ray->tex[Y] = clipped_screen_pixels * ray->tex_step;
}
