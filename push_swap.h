/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:02:59 by maneddam          #+#    #+#             */
/*   Updated: 2023/02/03 03:13:01 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "./printf/ft_printf.h"
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
void				ft_free(char **tab_2d);

t_node				*mylst_new(int content);
void				mylstadd_back(t_node **lst, t_node *new);
t_node				*mylst_last(t_node *lst);
void				mylstadd_front(t_node **lst, t_node *new);
int					mylst_size(t_node *lst);
void				ft_lstclear(t_node **lst, void (*del)(void *));
void				ft_lstdelone(t_node *lst, void (*del)(void *));

void				check_arg(char *one_arg, char **tab2d);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
long int			ft_atoi(const char *str);
void				check_args_num(char **tab2d);
int					is_not_sorted(t_node *stack_a);

void				swap(t_node **st_a, t_node **st_b, char c);
void				push(t_node **src, t_node **dest, char *str);
void				rotate(t_node **st_a, t_node **st_b, char c);
void				reverse_rotate(t_node **st_a, t_node **st_b, char c);
void				ss(t_node **st_a, t_node **st_b, int tmp);
void				rb(t_node **st_b, t_node *head, t_node *tmp);
void				rrb(t_node **st_b);

int					count_args(t_node **stack_a);
void				sort_three(t_node **stack_a, t_node **stack_b);
void				sort_five(t_node **stack_a, t_node **stack_b);
void				large_sort(t_node **stack_a, t_node **stack_b,
						t_args *infos);

int					*fill_and_sort_tab(t_node **stack_a, t_args *infos);

void				find_next_in_range(t_node **stack_a, t_node **stack_b,
						t_args *i);
int					in_range(t_node *stack_a, t_args *i);
void				push_back(t_node **stack_a, t_node **stack_b);
void				manipulate(t_node **stack_a, t_node **stack_b, t_args *i);
int					get_max_index(t_node *stack);
int					get_min_index(t_node *stack);
void				my_ft_free(char **tab_2d);
void				get_next_max(t_node **stack_a, t_node **stack_b);
int					check_and_push(t_node **stack_a, t_node **stack_b,
						int max_pos, int k);

int					get_index(int content, t_args *i);
void				index_stack(t_node **stack, t_args *i);
t_node				*get_last_in_a(t_node **stack_a);
t_node				get_max(t_node *stack);

#endif
