/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 20:32:31 by migarrid          #+#    #+#             */
/*   Updated: 2025/12/25 19:26:00 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}
/*#include <stdio.h>

int main(void)
{
	printf("Compare 'abc' y 'abc': %d\n", ft_strcmp("abc", "abc")); // 0
	printf("Comparando 'abc' y 'abd': %d\n", ft_strcmp("abc", "abd")); //-
	printf("Comparando 'abd' y 'abc': %d\n", ft_strcmp("abd", "abc")); //+
}*/
