/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:29:09 by maneddam          #+#    #+#             */
/*   Updated: 2023/02/02 21:34:56 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				index;
	int				content;
	struct s_node	*next;
}					t_node;

typedef struct s_args
{
	char			**tab2d;
	char			*one_arg;
	int				*arr;
	int				size;
	int				mid;
	int				offset;
	int				start;
	int				end;
}					t_args;

void				print_error(char *msg);
void				my_ft_free(char **tab_2d);

char				*join_args(int argc, char **argv);
t_node				*fill_stack(char **tab2d);
void				check_duplicate(char **tab2d);
void				check_arg(char *one_arg, char **tab2d);

t_node				*mylst_new(int content);
t_node				*mylst_last(t_node *lst);
void				mylstadd_back(t_node **lst, t_node *new);
void				mylstadd_front(t_node **lst, t_node *new);
int					mylst_size(t_node *lst);

void				swap(t_node **st_a, t_node **st_b, char c);
void				push(t_node **src, t_node **dest, char *str);
void				rotate(t_node **st_a, t_node **st_b, char c);
void				reverse_rotate(t_node **st_a, t_node **st_b, char c);
void				ss(t_node **st_a, t_node **st_b, int tmp);
void				rb(t_node **st_b, t_node *head, t_node *tmp);
void				rrb(t_node **st_b);

int					is_valid(char *s1, char *s2);
int					is_not_sorted(t_node *stack_a);

#endif
