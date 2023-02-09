/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:27:10 by maneddam          #+#    #+#             */
/*   Updated: 2023/01/31 16:35:31 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_node	*mylst_new(int content)
{
	t_node	*ptr;

	ptr = malloc(sizeof(t_node));
	if (!ptr)
		return (NULL);
	ptr->content = content;
	ptr->next = NULL;
	return (ptr);
}

t_node	*mylst_last(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	mylstadd_back(t_node **lst, t_node *new)
{
	if (*lst == NULL)
		*lst = new;
	else
	{
		mylst_last(*lst)->next = new;
	}
}

void	mylstadd_front(t_node **lst, t_node *new)
{
	if (*lst == NULL)
		*lst = mylst_new(new->content);
	else
	{
		new->next = *lst;
		*lst = new;
	}
}

int	mylst_size(t_node *lst)
{
	int	len;

	len = 0;
	if (lst == NULL)
		return (0);
	while (lst != NULL)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}
