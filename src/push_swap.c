/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:53:46 by maneddam          #+#    #+#             */
/*   Updated: 2023/02/03 21:01:02 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_full_of_spaces(char *arg)
{
	int	k;
	int	i;

	k = 1;
	i = 0;
	while (arg[i])
	{
		if (arg[i] != 32 && arg[i] != '\t')
			k = 0;
		i++;
	}
	return (k);
}

char	*join_args(int argc, char **argv)
{
	int		i;
	char	*line;
	char	*tmp;

	i = 1;
	line = NULL;
	while (i < argc)
	{
		if (!argv[i][0] || is_full_of_spaces(argv[i]))
			print_error("Error");
		tmp = line;
		line = ft_strjoin(line, " ");
		free(tmp);
		tmp = line;
		line = ft_strjoin(line, argv[i]);
		free(tmp);
		i++;
	}
	return (line);
}

t_node	*fill_stack(char **tab2d)
{
	t_node	*stack_a;
	long	nb;
	int		i;

	i = 0;
	while (tab2d[i])
	{
		nb = ft_atoi(tab2d[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			print_error("Error");
		if (i == 0)
			stack_a = mylst_new(nb);
		else
			mylstadd_back(&stack_a, mylst_new(nb));
		i++;
	}
	return (stack_a);
}

void	choose_func(t_node **stack_a, t_node **stack_b)
{
	t_args	i;

	i.size = count_args(stack_a);
	if (is_not_sorted(*stack_a))
	{
		if (i.size > 1 && i.size <= 3)
			sort_three(stack_a, stack_b);
		else if (i.size > 3 && i.size <= 5)
			sort_five(stack_a, stack_b);
		else if (i.size > 5)
		{
			large_sort(stack_a, stack_b, &i);
			free(i.arr);
		}
	}
}

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**tab2d;
	char	*one_arg;

	one_arg = join_args(argc, argv);
	tab2d = ft_split(one_arg, ' ');
	if (argc > 1)
	{
		check_arg(one_arg, tab2d);
		stack_a = fill_stack(tab2d);
		choose_func(&stack_a, &stack_b);
	}
}
