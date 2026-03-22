/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cross_product.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 01:54:44 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/21 01:55:21 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

/**
 * Calculates the 2D cross product (determinant) of two vectors.
 * The 2D cross product evaluates the relative orientation of two vectors.
 * It returns a positive value if the second vector is counter-clockwise
 * (to the left) of the first, zero if they are collinear, and a negative
 * value if it is clockwise (to the right).
 *
 * @param x1  The X component of the first vector.
 * @param y1  The Y component of the first vector.
 * @param x2  The X component of the second vector.
 * @param y2  The Y component of the second vector.
 * @return    The scalar 2D cross product of the two vectors as a double.
 */
double	ft_cross(double x1, double y1, double x2, double y2)
{
	double	product_1;
	double	product_2;
	double	cross_product;

	product_1 = x1 * y2;
	product_2 = y1 * x2;
	cross_product = product_1 - product_2;
	return (cross_product);
}
