/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 13:46:56 by avilla-m          #+#    #+#             */
/*   Updated: 2021/10/22 16:56:55 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(long int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 9)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*s;
	int			i;
	long int	long_n;

	i = ft_intlen(n);
	s = (char *)malloc((sizeof(char) * i) + 1);
	if (!s)
		return (0);
	if (n < 0)
	{
		s[0] = '-';
		long_n = -(long int)n;
	}
	else
		long_n = n;
	if (n == 0)
		s[0] = '0';
	s[i] = '\0';
	while (long_n >= 1)
	{
		s[--i] = (long_n % 10) + '0';
		long_n = long_n / 10;
	}
	return (s);
}
