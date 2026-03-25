/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float_fd_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 17:30:00 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/25 02:24:45 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

static void	ft_copy_string_parts(char *result, char *int_part, char *frac_part,
		int precision)
{
	int	pos;

	pos = 0;
	while (int_part[pos])
	{
		result[pos] = int_part[pos];
		pos++;
	}
	if (precision > 0)
	{
		result[pos++] = '.';
		ft_add_zeros(result, &pos, precision - ft_strlen(frac_part));
		while (*frac_part)
			result[pos++] = *frac_part++;
	}
	result[pos] = '\0';
}

static char	*ft_build_float_str(double f, int precision, int is_neg)
{
	char		*result;
	char		*int_str;
	char		*frac_str;
	long		multiplier;
	long long	tmp;

	multiplier = ft_power_10(precision);
	f = f * multiplier + 0.5;
	tmp = (long long)f;
	int_str = ft_itoa(tmp / multiplier);
	if (!int_str)
		return (NULL);
	frac_str = ft_itoa(tmp % multiplier);
	if (!frac_str)
		return (ft_free((void **)&int_str), NULL);
	tmp = ft_strlen(int_str) + is_neg + (precision > 0) * (1 + precision) + 1;
	result = ft_alloc(tmp, sizeof(char));
	if (!result)
		return (ft_free((void **)&int_str), ft_free((void **)&frac_str), NULL);
	if (is_neg)
		result[0] = '-';
	ft_copy_string_parts(result + is_neg, int_str, frac_str, precision);
	return (ft_free((void **)&int_str), ft_free((void **)&frac_str), result);
}

static char	*ft_float_to_str(double f, int precision)
{
	char	*result;
	int		is_negative;

	if (ft_is_special(f, &result))
		return (result);
	is_negative = (f < 0.0);
	if (is_negative)
		f = -f;
	return (ft_build_float_str(f, precision, is_negative));
}

int	ft_print_float_fd(double f, t_format *fmt, int fd)
{
	char	*str;
	int		precision;
	int		len;

	if (fmt->precision == -1)
		precision = 6;
	else
		precision = fmt->precision;
	str = ft_float_to_str(f, precision);
	if (!str)
		return (-1);
	ft_apply_flags(&str, fmt);
	len = ft_strlen(str);
	if (write(fd, str, len) == -1)
		return (-1);
	ft_free((void **)&str);
	return (len);
}
