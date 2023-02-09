/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:54:22 by maneddam          #+#    #+#             */
/*   Updated: 2023/02/01 23:18:59 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

size_t				ft_strlen(const char *s);
long				ft_atoi(const char *str);
int					ft_strchr(char *s, int c);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char *s1, char *s2);
char				**ft_split(char *s, char c);
int					is_valid(char *s1, char *s2);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(void *));

#endif
