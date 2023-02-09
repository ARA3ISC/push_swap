/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:28:40 by maneddam          #+#    #+#             */
/*   Updated: 2023/01/31 18:05:19 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchr(char *s, int c)
{
	size_t	i;
	size_t	len;
	int		count;

	if (s == NULL)
		return (0);
	i = 0;
	count = 0;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (s[i] == (char)c && s[i] != 32 && s[i] != '-')
			count++;
		i++;
	}
	return (count);
}
