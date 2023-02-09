/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 13:34:14 by maneddam          #+#    #+#             */
/*   Updated: 2023/02/02 23:53:04 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_node **st_a, t_node **st_b, char c)
{
	int	tmp;

	tmp = 0;
	if (c == 'a')
	{
		tmp = (*st_a)->content;
		(*st_a)->content = (*st_a)->next->content;
		(*st_a)->next->content = tmp;
		ft_putstr("sa\n");
	}
	else if (c == 'b')
	{
		tmp = (*st_b)->content;
		(*st_b)->content = (*st_b)->next->content;
		(*st_b)->next->content = tmp;
		ft_putstr("sb");
	}
	else if (c == 's')
		ss(st_a, st_b, tmp);
}

void	push(t_node **src, t_node **dest, char *str)
{
	t_node	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
	ft_putstr(str);
	ft_putstr("\n");
}

void	rotate(t_node **st_a, t_node **st_b, char c)
{
	t_node	*head;
	t_node	*tmp;

	head = NULL;
	tmp = NULL;
	if (c == 'a' && *st_a != NULL)
	{
		if (mylst_size(*st_a) < 2)
			return ;
		head = (*st_a);
		tmp = head;
		while (head->next != NULL)
			head = head->next;
		head->next = tmp;
		(*st_a) = (*st_a)->next;
		tmp->next = NULL;
		ft_putstr("ra\n");
	}
	if (c == 'b' && *st_b != NULL)
		rb(st_b, head, tmp);
}

void	reverse_rotate(t_node **st_a, t_node **st_b, char c)
{
	t_node	*head;
	t_node	*last;
	t_node	*before_end;

	if (c == 'a')
	{
		if (mylst_size(*st_a) < 2)
			return ;
		before_end = *st_a;
		while (before_end->next->next != NULL)
			before_end = before_end->next;
		last = *st_a;
		head = *st_a;
		while (last->next != NULL)
			last = last->next;
		last->next = *st_a;
		before_end->next = NULL;
		*st_a = last;
		ft_putstr("rra\n");
	}
	else if (c == 'b')
		rrb(st_b);
}
