/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:54:22 by maneddam          #+#    #+#             */
/*   Updated: 2022/11/05 00:45:52 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(long n, char *base);
int		ft_putnbr_add(unsigned long n, char *base);
int		ft_putnbr_u_dec(unsigned int n, char *base);
size_t	ft_strlen(const char *s);

#endif
