/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 21:46:21 by maneddam          #+#    #+#             */
/*   Updated: 2023/02/01 22:42:30 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_tab(int *tab, t_args *i)
{
	int	k;
	int	j;
	int	tmp;

	k = 0;
	while (k < i->size - 1)
	{
		j = k + 1;
		while (j < i->size)
		{
			if (tab[k] > tab[j])
			{
				tmp = tab[k];
				tab[k] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		k++;
	}
}

int	*fill_and_sort_tab(t_node **stack_a, t_args *infos)
{
	int		*tab;
	int		i;
	t_node	*tmp;

	tmp = *stack_a;
	tab = malloc((infos)->size * sizeof(int));
	if (!tab)
		return (0);
	i = 0;
	while (tmp != NULL)
	{
		tab[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	sort_tab(tab, infos);
	free(tmp);
	return (tab);
}

void	ra_or_rra(t_node **stack_a, t_node **stack_b, int k, int index)
{
	if (k < ((mylst_size(*stack_a) - 1) - index))
	{
		while (k-- > 0)
			rotate(stack_a, stack_b, 'a');
	}
	else
	{
		while (index++ < mylst_size(*stack_a) - 1)
			reverse_rotate(stack_a, stack_b, 'a');
	}
}

void	find_next_in_range(t_node **stack_a, t_node **stack_b, t_args *i)
{
	t_node	*tmp;
	int		k;
	int		p;
	int		index;

	k = 0;
	index = 0;
	tmp = *stack_a;
	p = mylst_size(*stack_a) / 2;
	while (k < p)
	{
		if (tmp->content <= i->arr[i->end])
			break ;
		k++;
		tmp = tmp->next;
	}
	tmp = *stack_a;
	while (p < mylst_size(*stack_a) - 1)
	{
		if (tmp->content <= i->arr[i->end])
			index = p;
		p++;
		tmp = tmp->next;
	}
	ra_or_rra(stack_a, stack_b, k, index);
}

int	in_range(t_node *stack_a, t_args *i)
{
	int	end;

	end = i->end;
	if (stack_a->content <= i->arr[end])
		return (1);
	return (0);
}
