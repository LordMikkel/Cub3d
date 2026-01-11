/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 23:37:59 by migarrid          #+#    #+#             */
/*   Updated: 2026/01/11 22:30:20 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

void	ft_lstdelone(t_list *lst, void (*del)(void **))
{
	if (!lst || !del)
		return ;
	del(&lst->content);
	ft_free((void **)&lst);
}
