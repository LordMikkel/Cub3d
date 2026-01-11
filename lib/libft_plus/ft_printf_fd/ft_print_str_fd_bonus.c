/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_fd_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:30:46 by migarrid          #+#    #+#             */
/*   Updated: 2026/01/11 22:57:57 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

int	ft_print_str_fd(char *str, t_format *fmt, int fd)
{
	int		len;
	char	*new_str;

	if (!str)
	{
		new_str = ft_strdup("(null)");
		if (!new_str)
			return (-1);
		ft_apply_flags(&new_str, fmt);
		if (!new_str)
			return (-1);
		len = write(fd, new_str, ft_strlen(new_str));
		ft_free((void **)&new_str);
		return (len);
	}
	new_str = ft_strdup(str);
	if (!new_str)
		return (-1);
	ft_apply_flags(&new_str, fmt);
	if (!new_str)
		return (-1);
	len = write(fd, new_str, ft_strlen(new_str));
	ft_free((void **)&new_str);
	return (len);
}
