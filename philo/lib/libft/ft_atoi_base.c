/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 10:03:37 by ametta            #+#    #+#             */
/*   Updated: 2021/12/09 15:58:29 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*kl_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

void	checking(const char *str, size_t *i, int *sign)
{
	*i = 0;
	*sign = 1;
	while (kl_strchr(" \t\v\r\n\f", str[*i]))
		(*i)++;
	while (kl_strchr("-+", str[*i]))
	{
		if (str[*i] == '-')
			(*sign) = -1;
		(*i)++;
	}
}

int	ft_atoi_base(const char *str, int base)
{
	size_t	i;
	int		sign;
	size_t	num;

	num = 0;
	i = 0;
	sign = 1;
	if (!str || base < 2 || base > 16)
		return (0);
	checking(str, &i, &sign);
	while (kl_strchr("0123456789ABCDEFabcdef", str[i]))
	{
		num = (num * base);
		if (kl_strchr("0123456789", str[i]))
			num += str[i] - '0';
		else if (kl_strchr("abcdef", str[i]))
			num += str[i] - ('a' - 10);
		else if (kl_strchr("ABCDEF", str[i]))
			num += str[i] - ('A' - 10);
		else
			return (0);
		i++;
	}
	return (num * sign);
}
