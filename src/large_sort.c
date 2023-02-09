/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 04:16:43 by maneddam          #+#    #+#             */
/*   Updated: 2023/02/03 03:10:58 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_back(t_node **stack_a, t_node **stack_b)
{
	int	max_pos;
	int	k;

	k = 0;
	if ((*stack_b)->content != get_max(*stack_b).content)
		k++;
	push(stack_b, stack_a, "pa");
	while (mylst_size(*stack_b) != 0)
	{
		max_pos = get_max(*stack_b).index;
		while (k != 0
			&& get_last_in_a(stack_a)->content > get_max(*stack_b).content)
		{
			reverse_rotate(stack_a, stack_b, 'a');
			k--;
		}
		k = check_and_push(stack_a, stack_b, max_pos, k);
		push(stack_b, stack_a, "pa");
	}
	while (k-- != 0)
		reverse_rotate(stack_a, stack_b, 'a');
}

void	send(t_node **stack_a, t_node **stack_b, t_args *i, int k)
{
	if (k > (mylst_size(*stack_a) - 1) / 2)
	{
		while (k < mylst_size(*stack_a))
		{
			reverse_rotate(stack_a, stack_b, 'a');
			k++;
		}
		push(stack_a, stack_b, "pb");
		if ((*stack_b)->index < i->end - (i->offset / 2))
			rotate(stack_a, stack_b, 'b');
	}
	else
	{
		while (k-- > 0)
			rotate(stack_a, stack_b, 'a');
		push(stack_a, stack_b, "pb");
		if ((*stack_b)->index < i->end - (i->offset / 2))
			rotate(stack_a, stack_b, 'b');
	}
}

void	begin_manipulating(t_node *tmp, t_node **stack_a, t_node **stack_b,
		t_args *i)
{
	int	k;

	k = 0;
	while (tmp != NULL)
	{
		if (tmp->index >= i->start && tmp->index <= i->end)
		{
			send(stack_a, stack_b, i, k);
			tmp = *stack_a;
			k = 0;
			continue ;
		}
		k++;
		tmp = tmp->next;
	}
}

void	manipulate(t_node **stack_a, t_node **stack_b, t_args *i)
{
	t_node	*tmp;

	index_stack(stack_a, i);
	while (mylst_size(*stack_a) != 0)
	{
		tmp = *stack_a;
		begin_manipulating(tmp, stack_a, stack_b, i);
		i->start += i->offset;
		i->end += i->offset;
		if (i->start > i->size - 1)
			break ;
	}
	push_back(stack_a, stack_b);
}

void	large_sort(t_node **stack_a, t_node **stack_b, t_args *i)
{
	i->arr = fill_and_sort_tab(stack_a, i);
	i->mid = (i->size - 1) / 2;
	i->offset = 0;
	if (i->size <= 100)
		i->offset = i->size / 5;
	else if (i->size > 100)
		i->offset = i->size / 11;
	i->start = 0;
	i->end = i->offset - 1;
	manipulate(stack_a, stack_b, i);
}
