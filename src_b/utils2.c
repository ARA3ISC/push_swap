/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 21:05:47 by maneddam          #+#    #+#             */
/*   Updated: 2023/02/02 21:35:15 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	my_ft_free(char **tab_2d)
{
	int	i;

	i = 0;
	while (tab_2d[i])
	{
		free(tab_2d[i]);
		i++;
	}
	free(tab_2d);
}

int	is_not_sorted(t_node *stack_a)
{
	int	i;

	i = 0;
	if (!stack_a)
		return (0);
	while (stack_a->next != NULL)
	{
		if (stack_a->content > stack_a->next->content)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

void	print_error(char *msg)
{
	ft_printf("%s\n", msg);
	exit(1);
}
