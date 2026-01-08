/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 03:07:33 by migarrid          #+#    #+#             */
/*   Updated: 2026/01/08 03:12:26 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

void	ft_str_replace(char **old_str, char *new_str)
{
	if (!old_str)
		return ;
	ft_free((void **)old_str);
	*old_str = new_str;
}
