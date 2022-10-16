/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:40:27 by avilla-m          #+#    #+#             */
/*   Updated: 2021/10/22 17:05:39 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchr_i(const char *s, int c)
{
	int	i;

	i = 0;
	while (*s || *(s - 1))
	{
		if (*(unsigned char *)s == (unsigned char)c)
			return (i);
		if (!*s)
			break ;
		s++;
		i++;
	}
	if (*(unsigned char *)s == (unsigned char)c)
		return (i);
	return (-1);
}
