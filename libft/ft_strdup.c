/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 08:14:10 by maneddam          #+#    #+#             */
/*   Updated: 2023/01/18 18:48:58 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	int		i;
	char	*ptr;

	len = 0;
	while (((char *)s1)[len])
		len++;
	ptr = malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = ((char *)s1)[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
