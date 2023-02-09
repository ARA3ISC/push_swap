/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:44:41 by maneddam          #+#    #+#             */
/*   Updated: 2023/02/03 19:34:28 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"
#include "../printf/ft_printf.h"
#include "checker.h"

int	invalid_op(char *str)
{
	if (is_valid(str, "sa\n") && is_valid(str, "sb\n") && is_valid(str, "ss\n")
		&& is_valid(str, "pa\n") && is_valid(str, "pb\n") && is_valid(str,
			"ra\n") && is_valid(str, "rb\n") && is_valid(str, "rr\n")
		&& is_valid(str, "rra\n") && is_valid(str, "rrb\n") && is_valid(str,
			"rrr\n"))
		return (1);
	return (0);
}

void	print_result(t_node **stack_a, t_node **stack_b)
{
	if (is_not_sorted(*stack_a) || mylst_size(*stack_b))
		print_error("KO");
	else
		ft_printf("OK\n");
}

void	checking2(t_node **st_a, t_node **st_b, char *str)
{
	if (!is_valid(str, "ra\n"))
		rotate(st_a, st_b, 'a');
	else if (!is_valid(str, "rb\n"))
		rotate(st_a, st_b, 'b');
	else if (!is_valid(str, "rr\n"))
	{
		rotate(st_a, st_b, 'a');
		rotate(st_a, st_b, 'b');
	}
	else if (!is_valid(str, "rra\n"))
		reverse_rotate(st_a, st_b, 'a');
	else if (!is_valid(str, "rrb\n"))
		reverse_rotate(st_a, st_b, 'b');
	else if (!is_valid(str, "rrr\n"))
	{
		reverse_rotate(st_a, st_b, 'b');
		reverse_rotate(st_a, st_b, 'a');
	}
}

void	checking1(t_node **st_a, t_node **st_b, char *str)
{
	if (!is_valid(str, "sa\n"))
		swap(st_a, st_b, 'a');
	else if (!is_valid(str, "sb\n"))
		swap(st_a, st_b, 'b');
	else if (!is_valid(str, "ss\n"))
	{
		swap(st_a, st_b, 'a');
		swap(st_a, st_b, 'b');
	}
	else if (!is_valid(str, "pa\n"))
		push(st_b, st_a, "pa");
	else if (!is_valid(str, "pb\n"))
		push(st_a, st_b, "pb");
	checking2(st_a, st_b, str);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**tab2d;
	char	*one_arg;
	char	*str;

	one_arg = join_args(argc, argv);
	tab2d = ft_split(one_arg, ' ');
	if (argc > 1)
	{
		check_arg(one_arg, tab2d);
		stack_a = fill_stack(tab2d);
		while (1)
		{
			str = get_next_line(0);
			if (!str)
				break ;
			if (invalid_op(str))
				print_error("Error");
			checking1(&stack_a, &stack_b, str);
			free(str);
		}
		print_result(&stack_a, &stack_b);
	}
}
