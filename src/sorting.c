/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 20:40:15 by maneddam          #+#    #+#             */
/*   Updated: 2023/02/01 22:40:43 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	count_args(t_node **stack_a)
{
	int		count;
	t_node	*tmp;

	tmp = *stack_a;
	count = 0;
	while (tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	free(tmp);
	return (count);
}

int	get_max_index(t_node *stack)
{
	int	max_index;
	int	max;
	int	i;

	max_index = 0;
	i = 0;
	max = stack->content;
	while (stack != NULL)
	{
		if (max < stack->content)
		{
			max = stack->content;
			i = max_index;
		}
		stack = stack->next;
		max_index++;
	}
	return (i);
}

int	get_min_index(t_node *stack)
{
	int	min_index;
	int	min;
	int	i;

	min_index = 0;
	i = 0;
	min = stack->content;
	while (stack != NULL)
	{
		if (min > stack->content)
		{
			min = stack->content;
			i = min_index;
		}
		stack = stack->next;
		min_index++;
	}
	return (i);
}

void	sort_three(t_node **stack_a, t_node **stack_b)
{
	int	min_index;
	int	max_index;

	min_index = get_min_index(*stack_a);
	max_index = get_max_index(*stack_a);
	if (max_index == 0 && min_index == 2)
	{
		rotate(stack_a, stack_b, 'a');
		swap(stack_a, stack_b, 'a');
	}
	if (max_index == 0 && min_index == 1)
		rotate(stack_a, stack_b, 'a');
	if (min_index == 1 && max_index == 2)
		swap(stack_a, stack_b, 'a');
	if (min_index == 2 && max_index != 0)
		reverse_rotate(stack_a, stack_b, 'a');
	if (min_index == 0 && max_index == 1)
	{
		swap(stack_a, stack_b, 'a');
		rotate(stack_a, stack_b, 'a');
	}
}

void	sort_five(t_node **stack_a, t_node **stack_b)
{
	int	count;
	int	min_index;

	count = count_args(stack_a);
	while (count > 3)
	{
		min_index = get_min_index(*stack_a);
		if (min_index <= count / 2)
		{
			while (min_index-- > 0)
				rotate(stack_a, stack_b, 'a');
		}
		else if (min_index > count / 2)
		{
			while (min_index++ < count)
				reverse_rotate(stack_a, stack_b, 'a');
		}
		push(stack_a, stack_b, "pb");
		count--;
	}
	if (count <= 3)
		sort_three(stack_a, stack_b);
	while ((*stack_b) != NULL)
		push(stack_b, stack_a, "pa");
}
