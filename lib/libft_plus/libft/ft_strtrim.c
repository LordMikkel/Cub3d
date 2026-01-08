/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 20:43:20 by migarrid          #+#    #+#             */
/*   Updated: 2026/01/08 01:30:43 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

char	*ft_strtrim(const char *str, const char *set)
{
	char	*trimmed;
	size_t	start;
	size_t	end;

	if (!str || !set)
		return (NULL);
	start = 0;
	while (str[start] && ft_strchr(set, str[start]))
		start++;
	end = ft_strlen(str);
	while (end > start && ft_strchr(set, str[end - 1]))
		end--;
	trimmed = (char *)malloc(end - start + 1);
	if (!trimmed)
		return (NULL);
	ft_strlcpy(trimmed, str + start, end - start + 1);
	return (trimmed);
}
/*#include <stdio.h>

int	main(int ac, char **av)
{
	if(ac == 3)
	{
		printf("String: %s\n", av[1]);
		printf("Trim: %s\n", av[2]);
		printf("String trimmed: %s\n", ft_strtrim(av[1], av[2]));
		return (0);
	}
	return (1);
}*/
