/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 21:41:56 by maneddam          #+#    #+#             */
/*   Updated: 2023/02/03 19:34:39 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstdelone(t_node *lst, void (*del)(void *))
{
	if (lst)
	{
		if (del)
			del(&lst->content);
		free(lst);
	}
}
