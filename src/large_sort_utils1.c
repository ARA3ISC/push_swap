/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort_utils1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 01:36:15 by maneddam          #+#    #+#             */
/*   Updated: 2023/02/03 01:20:38 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_index(int content, t_args *i)
{
	int	k;

	k = 0;
	while (k < i->size)
	{
		if (content == i->arr[k])
			return (k);
		k++;
	}
	return (k);
}

void	index_stack(t_node **stack, t_args *i)
{
	t_node	*head;

	head = *stack;
	while ((*stack) != NULL)
	{
		(*stack)->index = get_index((*stack)->content, i);
		(*stack) = (*stack)->next;
	}
	*stack = head;
}

t_node	*get_last_in_a(t_node **stack_a)
{
	t_node	*tmp;

	tmp = (*stack_a);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

t_node	get_max(t_node *stack)
{
	t_node	node;
	int		k;

	k = 0;
	node.content = stack->content;
	while (stack != NULL)
	{
		if (node.content < stack->content)
		{
			node.index = k;
			node.content = stack->content;
		}
		stack = stack->next;
		k++;
	}
	return (node);
}
