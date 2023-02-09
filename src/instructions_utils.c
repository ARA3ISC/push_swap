/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:06:21 by maneddam          #+#    #+#             */
/*   Updated: 2023/02/02 19:06:50 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ss(t_node **st_a, t_node **st_b, int tmp)
{
	tmp = (*st_a)->content;
	(*st_a)->content = (*st_a)->next->content;
	(*st_a)->next->content = tmp;
	tmp = (*st_b)->content;
	(*st_b)->content = (*st_b)->next->content;
	(*st_b)->next->content = tmp;
	ft_putstr("ss");
}

void	rb(t_node **st_b, t_node *head, t_node *tmp)
{
	if (mylst_size(*st_b) < 2)
		return ;
	head = (*st_b);
	tmp = head;
	while (head->next != NULL)
		head = head->next;
	head->next = tmp;
	(*st_b) = (*st_b)->next;
	tmp->next = NULL;
	ft_putstr("rb\n");
}

void	rrb(t_node **st_b)
{
	t_node	*head;
	t_node	*last;
	t_node	*before_end;

	if (mylst_size(*st_b) < 2)
		return ;
	before_end = *st_b;
	while (before_end->next->next != NULL)
		before_end = before_end->next;
	last = *st_b;
	head = *st_b;
	while (last->next != NULL)
		last = last->next;
	last->next = *st_b;
	before_end->next = NULL;
	*st_b = last;
	ft_putstr("rrb\n");
}
