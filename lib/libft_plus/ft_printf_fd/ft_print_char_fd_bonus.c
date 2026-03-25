/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_fd_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:31:04 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/25 02:29:47 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

static int	print_aligned(char c, char pad_char, t_format *fmt, int fd)
{
	int	pad_len;

	pad_len = 0;
	if (fmt->width > 1)
		pad_len = fmt->width - 1;
	if (!fmt->left_align)
	{
		while (pad_len-- > 0)
			if (write(fd, &pad_char, 1) < 0)
				return (-1);
		if (write(fd, &c, 1) < 0)
			return (-1);
	}
	else
	{
		if (write(fd, &c, 1) < 0)
			return (-1);
		while (pad_len-- > 0)
			if (write(fd, " ", 1) < 0)
				return (-1);
	}
	return (1);
}

int	ft_print_char_fd(char c, t_format *fmt, int fd)
{
	int		len;
	char	pad_char;

	if (fmt->width > 1)
		len = fmt->width;
	else
		len = 1;
	pad_char = ' ';
	if (fmt->zero_pad && !fmt->left_align)
		pad_char = '0';
	if (print_aligned(c, pad_char, fmt, fd) < 0)
		return (-1);
	return (len);
}
