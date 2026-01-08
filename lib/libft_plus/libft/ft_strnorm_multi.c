/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnorm_multi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 02:31:09 by migarrid          #+#    #+#             */
/*   Updated: 2026/01/08 02:51:27 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

static size_t	get_new_len(const char *str, const char *set)
{
	size_t	i;
	size_t	len;
	bool	in_repeat;

	i = 0;
	len = 0;
	in_repeat = false;
	while (str[i])
	{
		if (ft_strchr(set, str[i]))
		{
			if (!in_repeat)
			{
				len++;
				in_repeat = true;
			}
		}
		else
		{
			len++;
			in_repeat = false;
		}
		i++;
	}
	return (len);
}

static void	fill_str(char *new_str, const char *old_str, const char *set, int c)
{
	size_t	i;
	size_t	j;
	bool	in_repeat;

	i = 0;
	j = 0;
	in_repeat = false;
	while (old_str[i])
	{
		if (ft_strchr(set, old_str[i]))
		{
			if (!in_repeat)
			{
				new_str[j++] = (unsigned char)c;
				in_repeat = true;
			}
		}
		else
		{
			new_str[j++] = old_str[i];
			in_repeat = false;
		}
		i++;
	}
	new_str[j] = '\0';
}

char	*ft_strnorm_multi(const char *str, const char *set, int c)
{
	char	*new_str;
	size_t	len;

	if (!str || !set)
		return (NULL);
	len = get_new_len(str, set);
	new_str = ft_calloc(len + 1, sizeof(char));
	if (!new_str)
		return (NULL);
	fill_str(new_str, str, set, c);
	return (new_str);
}
