/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_plus_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:14:53 by migarrid          #+#    #+#             */
/*   Updated: 2026/01/11 23:00:50 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

void	ft_apply_plus(char **str, t_format *fmt)
{
	char	*new_str;

	if (fmt->plus && (*str)[0] != '-')
	{
		new_str = ft_strjoin("+", *str);
		if (!new_str)
		{
			ft_free((void **)str);
			return ;
		}
		ft_free((void **)str);
		*str = new_str;
	}
}
