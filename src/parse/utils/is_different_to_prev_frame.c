/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_different_to_prev_frame.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 16:20:12 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/08 16:32:28 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

bool	is_different_to_prev_frame(t_txtr *prev_frame, t_txtr *frame)
{
	if (prev_frame && prev_frame != frame && prev_frame->img)
		return (TRUE);
	return (FALSE);
}
