/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 23:26:17 by migarrid          #+#    #+#             */
/*   Updated: 2026/01/11 22:31:38 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

static size_t	count_substrings(const char *s, char c)
{
	size_t	counter;
	int		delimiter;

	counter = 0;
	delimiter = 1;
	while (*s)
	{
		if (*s == c)
			delimiter = 1;
		else if (delimiter)
		{
			counter++;
			delimiter = 0;
		}
		s++;
	}
	return (counter);
}

static int	substring(char **array, size_t *i, const char *start, size_t len)
{
	array[*i] = ft_alloc(len + 1, sizeof(char));
	if (!array[*i])
	{
		while (*i > 0)
			ft_free((void **)&array[--(*i)]);
		return (0);
	}
	ft_memcpy(array[*i], start, len);
	array[(*i)++][len] = '\0';
	return (1);
}

static char	**fill_array(char **array, const char *s, char c)
{
	size_t		i;
	size_t		len;
	const char	*start;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != '\0')
		{
			start = s;
			while (*s && *s != c)
				s++;
			len = s - start;
			if (!substring(array, &i, start, len))
				return (NULL);
		}
	}
	array[i] = NULL;
	return (array);
}

char	**ft_split(const char *s, char c)
{
	char	**array;
	size_t	counter;

	if (!s)
		return (NULL);
	counter = count_substrings(s, c);
	array = ft_alloc((counter + 1), sizeof(char *));
	if (!array)
		return (NULL);
	if (!fill_array(array, s, c))
	{
		ft_free((void **)&array);
		return (NULL);
	}
	return (array);
}
