/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_gun.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 20:16:03 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/22 17:27:52 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

/**
 * Retrieves the exact texture pointer for the weapon's current animation.
 * Maps the active gun state to its corresponding array of texture frames
 * and fetches the texture at the current frame index.
 *
 * @param gun  The weapon structure to extract the frame from.
 * @return     Pointer to the specific texture struct for the current frame.
 */
static t_txtr	*select_frame(t_gun *gun)
{
	if (gun->state == GUN_IDLE_A)
		return (&gun->idle_frames[gun->current_frame]);
	if (gun->state == GUN_IDLE_E)
		return (&gun->empty_frames[gun->current_frame]);
	if (gun->state == GUN_AIM || gun->state == GUN_UNAIM)
		return (&gun->aim_frames[gun->current_frame]);
	if (gun->state == GUN_SHOOT)
		return (&gun->shoot_frames[gun->current_frame]);
	if (gun->state == GUN_MELEE)
		return (&gun->melee_frames[gun->current_frame]);
	if (gun->state == GUN_RELOAD)
		return (&gun->reload_frames[gun->current_frame]);
	return (&gun->idle_frames[0]);
}

/**
 * Orchestrates the rendering of the weapon on the screen.
 * Fetches the correct texture for the current animation frame
 * and passes it to the underlying drawing function.
 * Only the pixels inside the area are drawn, so every render thread can
 * draw the gun on its own columns.
 *
 * @param data  Main program struct.
 * @param gun   The weapon structure to be rendered.
 * @param area  [MIN_X, MAX_X, MIN_Y, MAX_Y] screen area allowed to draw.
 */
void	render_gun(t_data *data, t_gun *gun, int *area)
{
	t_txtr	*frame;

	frame = select_frame(gun);
	if (!frame || !frame->txtr)
		return ;
	draw_gun(data, frame, area);
}
