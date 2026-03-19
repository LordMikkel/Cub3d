/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_distance.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 21:15:55 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/20 00:20:16 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

/**
 * Calculates the Euclidean distance between two points in a 2D space.
 * Uses the Pythagorean theorem (d = sqrt(dx^2 + dy^2)).
 * Direct multiplication (dx * dx) is favored over the standard pow() function
 * to avoid the overhead of complex floating-point exponentiation, ensuring
 * optimal execution time across all general-purpose applications.
 *
 * @param x1  The X coordinate of the first point.
 * @param y1  The Y coordinate of the first point.
 * @param x2  The X coordinate of the second point.
 * @param y2  The Y coordinate of the second point.
 * @return    The straight-line distance between the two points as a double.
 */
double	ft_dist(double x1, double y1, double x2, double y2)
{
	double	dx;
	double	dy;
	double	distance;

	dx = x2 - x1;
	dy = y2 - y1;
	distance = sqrt((dx * dx) + (dy * dy));
	return (distance);
}
