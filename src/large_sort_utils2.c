/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 03:11:17 by maneddam          #+#    #+#             */
/*   Updated: 2023/02/03 03:11:40 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	get_next_max(t_node **stack_a, t_node **stack_b)
{
	t_node	data;

	data = get_max(*stack_b);
	while (data.index-- > 0)
	{
		rotate(stack_a, stack_b, 'b');
		data = get_max(*stack_b);
	}
}

int	check_and_push(t_node **stack_a, t_node **stack_b, int max_pos, int k)
{
	if (max_pos > (mylst_size(*stack_b) + 1) / 2)
	{
		while (max_pos++ < mylst_size(*stack_b))
			reverse_rotate(stack_a, stack_b, 'b');
	}
	else
	{
		while (get_max(*stack_b).content != (*stack_b)->content)
		{
			if (k == 0 || (*stack_b)->content > get_last_in_a(stack_a)->content)
			{
				push(stack_b, stack_a, "pa");
				rotate(stack_a, stack_b, 'a');
				k++;
			}
			else
				get_next_max(stack_a, stack_b);
		}
	}
	return (k);
}
