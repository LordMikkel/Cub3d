/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_str_in_arr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: king <king@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 10:35:02 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/12/21 00:07:54 by king             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

size_t	ft_arraylen(char **str_array)
{
	size_t	count;

	if (!str_array)
		return (0);
	count = 0;
	while (str_array[count] != NULL)
		count++;
	return (count);
}
