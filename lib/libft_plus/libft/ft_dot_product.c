/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dot_product.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 23:25:28 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/21 01:54:27 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

/**
 * Calculates the dot product (scalar product) of two 2D vectors.
 * The dot product evaluates the directional relationship between two vectors.
 * It returns a positive value if they point in a similar direction, zero if
 * they are exactly perpendicular, and a negative value if they point away
 * from each other.
 *
 * @param x1  The X component of the first vector.
 * @param y1  The Y component of the first vector.
 * @param x2  The X component of the second vector.
 * @param y2  The Y component of the second vector.
 * @return    The scalar dot product of the two vectors as a double.
 */
double	ft_dot(double x1, double y1, double x2, double y2)
{
	double	product_x;
	double	product_y;
	double	dot_product;

	product_x = x1 * x2;
	product_y = y1 * y2;
	dot_product = product_x + product_y;
	return (dot_product);
}
