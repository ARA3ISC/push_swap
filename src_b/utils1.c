/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:49:55 by maneddam          #+#    #+#             */
/*   Updated: 2023/02/03 03:40:36 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	check_duplicate(char **tab2d)
{
	int	i;
	int	j;
	int	n1;
	int	n2;

	i = 0;
	while (tab2d[i])
	{
		if (!tab2d[i][0])
			print_error("Error");
		n1 = ft_atoi(tab2d[i]);
		j = i + 1;
		while (tab2d[j])
		{
			n2 = ft_atoi(tab2d[j]);
			if (n1 == n2)
				print_error("Error");
			j++;
		}
		i++;
	}
}

void	check_arg(char *one_arg, char **tab2d)
{
	int	i;

	i = 0;
	while (one_arg[i])
	{
		if (!(one_arg[i] >= '0' && one_arg[i] <= '9') && one_arg[i] != 32
			&& one_arg[i] != '-' && one_arg[i] != '+')
			print_error("Error");
		i++;
	}
	check_duplicate(tab2d);
}
